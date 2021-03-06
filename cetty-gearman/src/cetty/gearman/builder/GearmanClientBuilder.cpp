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

#include <cetty/gearman/builder/GearmanClientBuilder.h>

#include <cetty/channel/ChannelPipeline.h>
#include <cetty/handler/codec/LengthFieldBasedFrameDecoder.h>
#include <cetty/gearman/GearmanClient.h>
#include <cetty/gearman/GearmanClientHandler.h>
#include <cetty/gearman/protocol/GearmanMessageCodec.h>

namespace cetty {
namespace gearman {
namespace builder {

using namespace cetty::channel;
using namespace cetty::handler::codec;
using namespace cetty::service::builder;
using namespace cetty::gearman;

GearmanClientBuilder::GearmanClientBuilder()
    : builder_() {
    init();
}

GearmanClientBuilder::GearmanClientBuilder(int threadCnt)
    : builder_(threadCnt) {
    init();
}

GearmanClientBuilder::GearmanClientBuilder(const EventLoopPoolPtr& eventLoopPool)
    : builder_(eventLoopPool) {
    init();
}

GearmanClientBuilder::GearmanClientBuilder(const EventLoopPtr& eventLoop)
    :  builder_(eventLoop) {
    init();
}

bool initializeChannel(ChannelPipeline& pipeline) {
    pipeline.addLast<LengthFieldBasedFrameDecoder::HandlerPtr>("frameDecoder",
        LengthFieldBasedFrameDecoder::HandlerPtr(
        new LengthFieldBasedFrameDecoder(16 * 1024 * 1024, 8, 4, 0, 4)));

    pipeline.addLast<GearmanMessageCodec::HandlerPtr>("gearmanCodec",
        GearmanMessageCodec::HandlerPtr(new GearmanMessageCodec));

    pipeline.addLast<GearmanClientHandler::HandlerPtr>("gearmanClient",
        GearmanClientHandler::HandlerPtr(new GearmanClientHandler));

    return true;
}

void GearmanClientBuilder::init() {
    builder_.setClientInitializer(boost::bind(&initializeChannel, _1));
}

cetty::gearman::GearmanClientPtr GearmanClientBuilder::build() {
    return new GearmanClient(builder_.build());
}

GearmanClientBuilder& GearmanClientBuilder::addConnection(const std::string& host, int port) {
    builder_.addConnection(host, port, 1);
    return *this;
}

}
}
}
