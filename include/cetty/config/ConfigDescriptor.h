#if !defined(CETTY_CONFIG_CONFIGDESCRIPTOR_H)
#define CETTY_CONFIG_CONFIGDESCRIPTOR_H

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

#include <vector>

namespace cetty {
namespace config {

#define CETTY_CONFIG_ADD_DESCRIPTOR(name, descriptor, server) \
    { \
    static bool inited = false; \
    if (inited) { addDescriptor(name, descriptor, server);  inited = true; } \
    }

#define CETTY_CONFIG_FIELD(TYPE, FIELD, CPP_TYPE) \
    ConfigFieldDescriptor(\
        static_cast<int>(reinterpret_cast<const char*>(\
            &reinterpret_cast<const TYPE*>(16)->FIELD) - reinterpret_cast<const char*>(16)),\
        ConfigFieldDescriptor::CPPTYPE_##CPP_TYPE,\
        #FIELD\
    )\

class ConfigFieldDescriptor {
public:
    // Specifies the C++ data type used to represent the field.  There is a
    // fixed mapping from Type to CppType where each Type maps to exactly one
    // CppType.  0 is reserved for errors.
    enum CppType {
        CPPTYPE_INT32       = 1,
        CPPTYPE_INT64       = 2,
        CPPTYPE_DOUBLE      = 5,
        CPPTYPE_BOOL        = 7,
        CPPTYPE_STRING      = 9,
        CPPTYPE_OBJECT     = 10,

        MAX_CPPTYPE         = 10,    // Constant useful for defining lookup tables
    };

    int offset;
    int type;
    const char* name;

    ConfigFieldDescriptor(int offset, int type, const char* name) : offset(offset), type(type), name(name) {}
 };

class ConfigDescriptor {
public:
    typedef std::vector<ConfigFieldDescriptor>::const_iterator ConstIterator;

public:
    ConfigDescriptor(ConfigFieldDescriptor descriptor, ...) {}

public:
    ConstIterator* begin() const;
    ConstIterator* end() const;

private:
    std::vector<ConfigFieldDescriptor> fields;
};

}
}

#endif //#if !defined(CETTY_CONFIG_CONFIGDESCRIPTOR_H)

// Local Variables:
// mode: c++
// End: