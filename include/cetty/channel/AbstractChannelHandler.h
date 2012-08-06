#if !defined(CETTY_CHANNEL_ABSTRACTCHANNELHANDLER_H)
#define CETTY_CHANNEL_ABSTRACTCHANNELHANDLER_H

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

#include <cetty/channel/AbstractChannelInboundHandler.h>
#include <cetty/channel/AbstractChannelOutboundHandler.h>

namespace cetty {
namespace channel {

class AbstractChannelHandler
    : public AbstractChannelInboundHandler,
      public AbstractChannelOutboundHandler {
public:
    virtual ~AbstractChannelHandler() {}

    virtual void beforeAdd(ChannelHandlerContext& ctx);
    virtual void afterAdd(ChannelHandlerContext& ctx);
    virtual void beforeRemove(ChannelHandlerContext& ctx);
    virtual void afterRemove(ChannelHandlerContext& ctx);

    virtual void exceptionCaught(ChannelHandlerContext& ctx,
                                 const ChannelException& cause);

    virtual void userEventTriggered(ChannelHandlerContext& ctx,
                                const UserEvent& evt);

    virtual ChannelHandlerContext* createContext(const std::string& name,
            ChannelPipeline& pipeline,
            ChannelHandlerContext* prev,
            ChannelHandlerContext* next);

    virtual ChannelHandlerContext* createContext(const std::string& name,
            const EventLoopPtr& eventLoop,
            ChannelPipeline& pipeline,
            ChannelHandlerContext* prev,
            ChannelHandlerContext* next);
};

}
}

#endif //#if !defined(CETTY_CHANNEL_ABSTRACTCHANNELHANDLER_H)

// Local Variables:
// mode: c++
// End: