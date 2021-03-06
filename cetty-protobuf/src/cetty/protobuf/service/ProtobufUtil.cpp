/*
 * Copyright (c) 2010-2012 frankee zhou (frankee.zhou at gmail dot com)
 *
 * Distributed under under the Apache License, version 2.0 (the "License").
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#include <cetty/protobuf/service/ProtobufUtil.h>
#include <boost/bind.hpp>
#include <cetty/util/Adler32.h>

#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>

#include <cetty/logging/Logger.h>
#include <cetty/logging/LogLevel.h>

#include <cetty/config/ConfigObject.h>
#include <cetty/config/ConfigDescriptor.h>

namespace cetty {
namespace protobuf {
namespace service {

using namespace google::protobuf;
using namespace cetty::logging;
using namespace cetty::config;

ProtobufUtil::FieldValue ProtobufUtil::getMessageFieldValue(const Message& message,
        const std::string& name) {

    std::string fieldName;
    std::string subFieldName;
    std::string::size_type pos = name.find(".");

    if (pos != name.npos) {
        fieldName = name.substr(0, pos);
        subFieldName = name.substr(pos + 1);
    }
    else {
        fieldName = name;
    }

    const google::protobuf::Reflection* reflection = message.GetReflection();
    const google::protobuf::Descriptor* descriptor = message.GetDescriptor();
    int fieldCnt = descriptor->field_count();

    for (int i = 0; i < fieldCnt; ++i) {
        const google::protobuf::FieldDescriptor* field = descriptor->field(i);

        if (field->name() != fieldName) {
            continue;
        }

        if (subFieldName.empty()) {
            if (!field->is_repeated()) {
                switch (field->cpp_type()) {
                case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                    return (int64_t)reflection->GetInt32(message, field);
                    break;

                case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                    return reflection->GetInt64(message, field);
                    break;

                case  google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                    return reflection->GetDouble(message, field);
                    break;

                case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
                    return &(reflection->GetStringReference(message, field, NULL));
                    break;

                case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
                    return &(reflection->GetMessage(message, field));

                default:
                    return FieldValue();
                }
            }
            else {
                int i = 0;
                int fieldCnt = reflection->FieldSize(message, field);

                std::vector<int64_t> integers;
                std::vector<double> doubles;
                std::vector<const std::string*> strings;
                std::vector<const Message*> messages;

                switch (field->cpp_type()) {
                case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                    for (i = 0; i < fieldCnt; ++i) {
                        integers.push_back(reflection->GetRepeatedInt32(message, field, i));
                    }

                    return integers;
                    break;

                case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                    for (i = 0; i < fieldCnt; ++i) {
                        integers.push_back(reflection->GetRepeatedInt64(message, field, i));
                    }

                    return integers;
                    break;

                case  google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                    for (i = 0; i < fieldCnt; ++i) {
                        doubles.push_back(reflection->GetRepeatedDouble(message, field, i));
                    }

                    return doubles;
                    break;

                case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
                    for (i = 0; i < fieldCnt; ++i) {
                        strings.push_back(&reflection->GetRepeatedStringReference(message, field, i, NULL));
                    }

                    return strings;
                    break;

                case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
                    for (i = 0; i < fieldCnt; ++i) {
                        messages.push_back(&reflection->GetRepeatedMessage(message, field, i));
                    }

                    return messages;

                default:
                    return FieldValue();
                }
            }
        }
        else {
            return getMessageFieldValue(reflection->GetMessage(message, field), subFieldName);
        }
    }

    return FieldValue();
}

static LogLevel changeLogLevel(google::protobuf::LogLevel level) {
    switch (level) {
    case google::protobuf::LOGLEVEL_WARNING:
        return LogLevel::WARN;

    case google::protobuf::LOGLEVEL_ERROR:
        return LogLevel::ERROR;

    case google::protobuf::LOGLEVEL_FATAL:
        return LogLevel::FATAL;

    case google::protobuf::LOGLEVEL_INFO:
        return LogLevel::INFO;

    default:
        return LogLevel::INFO;
    }
}

void ProtobufUtil::logHandler(google::protobuf::LogLevel level,
                              const char* filename,
                              int line,
                              const std::string& message) {
    LogLevel logLevel = changeLogLevel(level);

    //if (muduo::Logger::logLevel() <= logLevel) {
    Logger(Logger::SourceFile(filename, strlen(filename)),
           line,
           logLevel).stream() << "Protobuf - " << message;
    //}
}

bool ProtobufUtil::mergeObject(const ConfigObject& config, Message* message) {
    const google::protobuf::Descriptor* descriptor = message->GetDescriptor();
    const ConfigObjectDescriptor* configDescriptor = config.descriptor();

    int fieldCnt = descriptor->field_count();

    for (int i = 0; i < fieldCnt; ++i) {
        const google::protobuf::FieldDescriptor* field = descriptor->field(i);
        const ConfigFieldDescriptor* configField =
            configDescriptor->field(field->camelcase_name());

        if (configField && config.has(configField)) {
            if (!mergeField(configField, config, field, message)) {
                return false;
            }
        }
    }
}

bool ProtobufUtil::mergeField(const ConfigFieldDescriptor* configField, const ConfigObject& config, const FieldDescriptor* field, Message* message) {
    const google::protobuf::Reflection* reflection = message->GetReflection();
    const FieldDescriptor::CppType& cppType = field->cpp_type();
    int configType = configField->cppType;

    bool repeated = field->is_repeated();
    int  repeatedType = configField->repeatedType;

    if (cppType == FieldDescriptor::CPPTYPE_BOOL && cppType == configType) {
        if (repeated) {
            if (repeatedType == ConfigFieldDescriptor::LIST) {

            }
            else if (repeatedType == ConfigFieldDescriptor::MAP) {

            }
        }
        else {
            if (repeatedType == ConfigFieldDescriptor::NO_REPEATED) {
                reflection->SetInt32(message,
                    field,
                    config.get<bool>(configField));
            }
        }
    }
    else if (cppType == FieldDescriptor::CPPTYPE_INT32 && cppType == configType) {
        if (repeated) {
            if (repeatedType == ConfigFieldDescriptor::LIST) {
                const std::vector<int>& values = config.get<std::vector<int> >(configField);

                for (std::size_t i = 0; i < values.size(); ++i) {
                    reflection->AddInt32(message, field, values[i]);
                }
            }
            else if (repeatedType == ConfigFieldDescriptor::MAP) {
                const std::map<std::string, int>& values =
                    config.get<std::map<std::string, int> >(configField);
                std::map<std::string, int>::const_iterator itr = values.begin();

                for (; itr != values.end(); ++itr) {
                    reflection->AddInt32(message, field, itr->second);
                }
            }
        }
        else {
            if (repeatedType == ConfigFieldDescriptor::NO_REPEATED) {
                reflection->SetInt32(message,
                    field,
                    config.get<int>(configField));
            }
        }
    }
    else if (cppType == FieldDescriptor::CPPTYPE_MESSAGE && cppType == configType) {
        if (repeated) {
            if (repeatedType == ConfigFieldDescriptor::LIST) {
                const std::vector<ConfigObject*>& values =
                    config.get<std::vector<ConfigObject*> >(configField);

                for (std::size_t i = 0; i < values.size(); ++i) {
                    Message* msg = reflection->AddMessage(message, field);

                    if (!mergeObject(*values[i], msg)) {
                        return false;
                    }
                }
            }
            else if (repeatedType == ConfigFieldDescriptor::MAP) {
                const std::map<std::string, ConfigObject*>& values =
                    config.get<std::map<std::string, ConfigObject*> >(configField);
                std::map<std::string, ConfigObject*>::const_iterator itr =
                    values.begin();

                for (; itr != values.end(); ++itr) {
                    Message* msg = reflection->AddMessage(message, field);

                    if (!mergeObject(*itr->second, msg)) {
                        return false;
                    }
                }
            }
            else {
                Message* msg = reflection->AddMessage(message, field);
                return mergeObject(*config.get<ConfigObject*>(configField), msg);
            }
        }
        else {
            if (repeatedType == ConfigFieldDescriptor::NO_REPEATED) {
                Message* msg = reflection->MutableMessage(message, field);
                return mergeObject(*config.get<ConfigObject*>(configField), msg);
            }
        }
    }

    return 0;
}



static uint32_t adler32Check(const uint8_t* buffer, int bufferSize) {
    return static_cast<uint32_t>(
               cetty::util::Adler32::adler32(reinterpret_cast<char const*>(buffer),
                       bufferSize));
}

ProtobufUtil::ChecksumFunction ProtobufUtil::adler32Checksum =
    boost::bind(&adler32Check,
                _1,
                _2);

}
}
}
