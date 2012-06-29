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

#include <cetty/gearman/GearmanEncoder.h>

#include <cetty/channel/ChannelMessage.h>
#include <cetty/gearman/GearmanMessage.h>

namespace cetty {
namespace gearman {

using namespace cetty::channel;
using namespace cetty::buffer;

GearmanEncoder::GearmanEncoder() {

}

GearmanEncoder::~GearmanEncoder() {

}

ChannelHandlerPtr GearmanEncoder::clone() {
    return ChannelHandlerPtr(new GearmanEncoder);
}

std::string GearmanEncoder::toString() const {
    return "GearmanEncoder";
}

ChannelMessage GearmanEncoder::encode(ChannelHandlerContext& ctx,
                                      const ChannelPtr& channel,
                                      const ChannelMessage& msg) {

    GearmanMessagePtr message = msg.smartPointer<GearmanMessage>();

    if (message) {
        int parametersLength = caculateParametersLength(message);
        int headerLength = 12;
        //int bodyLenth = parametersLength;
        int bodyLenth = 0;
        int messageLength = 0;

        //如果有hasData
        if (message->hasData()) {
            const ChannelBufferPtr& data = message->getData();
            bodyLenth += data->readableBytes();
            messageLength = bodyLenth + parametersLength;

            //往前面写
            if (data->aheadWritableBytes() >= parametersLength + headerLength) {
                if (parametersLength) {
                    writeParametersAhead(data, message->getParameters(), true);
                }

                writeHeaderAhead(data, message->getType(), messageLength);
                //to check the data
                std::string ret = ChannelBuffers::hexDump(data);
                std::cout<<"the send data is "<<ret<<std::endl;
                return ChannelMessage(data);
            }
            else {
                //如果不够就重新创建个channelbuffer
                ChannelBufferPtr buffer = ChannelBuffers::buffer(messageLength + headerLength);

                writeHeader(buffer, message->getType(), messageLength);

                if (parametersLength) {
                    writeParameters(buffer, message->getParameters(), true);
                }

                //写data
                buffer->writeBytes(data);
                //to check the data
                std::string ret = ChannelBuffers::hexDump(buffer);
                std::cout<<"the send data is "<<ret<<std::endl;
                return ChannelMessage(buffer);
            }
        }
        else {
            //if (bodyLenth) { //no need to remove the last zero pad
            //  --bodyLenth;
            //}
            //
            //messageLength = bodyLenth + headerLength;


            if (message->getParameters().size() != 0) {
                messageLength =  parametersLength - 1;
            }
            else {
                messageLength =  parametersLength;
            }

            ChannelBufferPtr buffer = ChannelBuffers::buffer(messageLength+headerLength);
            writeHeader(buffer, message->getType(), messageLength);

            if ((parametersLength - 1) > 0) {
                writeParameters(buffer, message->getParameters(), false);
            }

            //to check the data
            std::string ret = ChannelBuffers::hexDump(buffer);
            std::cout<<"the send data is "<<ret<<std::endl;
            return ChannelMessage(buffer);
        }
    }
    else {
        return msg;
    }
}

int GearmanEncoder::caculateParametersLength(const GearmanMessagePtr& msg) {
    int length = 0;

    const std::vector<std::string>& parameters = msg->getParameters();

    for (int i = 0, j = parameters.size(); i < j; ++i) {
        length += parameters[i].size();
        length += 1;
    }

    return length;
}

void GearmanEncoder::writeHeader(const ChannelBufferPtr& buffer, int type, int length) {
    buffer->writeBytes(GearmanMessage::REQUEST_MAGIC);
    buffer->writeInt(type);
    buffer->writeInt(length);
}

void GearmanEncoder::writeHeaderAhead(const ChannelBufferPtr& buffer, int type, int length) {
    buffer->writeIntAhead(length);
    buffer->writeIntAhead(type);
    buffer->writeBytesAhead(GearmanMessage::REQUEST_MAGIC);
}

void GearmanEncoder::writeParameters(const ChannelBufferPtr& buffer,
                                     const std::vector<std::string>& parameters,
                                     bool withZeroPad) {
    int j = parameters.size();

    for (int i = 0; i < j; ++i) {
        buffer->writeBytes(parameters[i]);

        if (!withZeroPad && ((j - i) == 1)) {
            // last one no zero pad
            break;
        }

        buffer->writeByte(0);
    }
}

void GearmanEncoder::writeParametersAhead(const ChannelBufferPtr& buffer,
        const std::vector<std::string>& parameters,
        bool withZeroPad) {
    int j = parameters.size();

    if (j == 0) { return; }

    if (withZeroPad) {
        buffer->writeByteAhead(0);
    }

    buffer->writeBytesAhead(parameters[j - 1]);

    for (int i = j - 2; i >= 0; --i) {
        buffer->writeByteAhead(0);
        buffer->writeBytesAhead(parameters[i]);
    }
}

}
}
