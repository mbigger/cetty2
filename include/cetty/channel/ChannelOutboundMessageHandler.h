#if !defined(CETTY_CHANNEL_CHANNELOUTBOUNDMESSAGEHANDLER_H)
#define CETTY_CHANNEL_CHANNELOUTBOUNDMESSAGEHANDLER_H

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

#include <cetty/channel/ChannelOutboundHandler.h>
#include <cetty/channel/ChannelOutboundMessageHandlerContext.h>

namespace cetty {
namespace channel {

template<typename OutboundInT>
class ChannelOutboundMessageHandler : public ChannelOutboundHandler {
public:
    typedef ChannelOutboundMessageHandlerContext<OutboundInT> OutboundMessageContext;

public:
    ChannelOutboundMessageHandler() {}
    virtual~ ChannelOutboundMessageHandler() {}

    virtual void bind(ChannelHandlerContext& ctx,
                      const SocketAddress& localAddress,
                      const ChannelFuturePtr& future) {
        ctx.bind(localAddress, future);
    }

    virtual void connect(ChannelHandlerContext& ctx,
                         const SocketAddress& remoteAddress,
                         const SocketAddress& localAddress,
                         const ChannelFuturePtr& future) {
        ctx.connect(remoteAddress, localAddress, future);
    }

    virtual void disconnect(ChannelHandlerContext& ctx,
                            const ChannelFuturePtr& future) {
        ctx.disconnect(future);
    }

    virtual void close(ChannelHandlerContext& ctx,
                       const ChannelFuturePtr& future) {
        ctx.close(future);
    }

    virtual void flush(ChannelHandlerContext& ctx,
                       const ChannelFuturePtr& future) {
        OutboundMessageContext* context =
            ctx.outboundMessageHandlerContext<OutboundMessageContext>();

        if (context) {
            flush(*context, future);
        }
        else {
            ctx.flush(future);
        }
    }

    virtual void beforeAdd(ChannelHandlerContext& ctx) {}

    virtual void afterAdd(ChannelHandlerContext& ctx) {}

    virtual void beforeRemove(ChannelHandlerContext& ctx) {}

    virtual void afterRemove(ChannelHandlerContext& ctx) {}

    virtual void exceptionCaught(ChannelHandlerContext& ctx,
                                 const ChannelException& cause) {
        ctx.fireExceptionCaught(cause);
    }

    virtual void userEventTriggered(ChannelHandlerContext& ctx,
                                const UserEvent& evt) {
        ctx.fireUserEventTriggered(evt);
    }

    virtual ChannelHandlerContext* createContext(const std::string& name,
            ChannelPipeline& pipeline,
            ChannelHandlerContext* prev,
            ChannelHandlerContext* next) {
        return new ChannelOutboundMessageHandlerContext<OutboundInT>(name,
                pipeline,
                shared_from_this(),
                prev,
                next);
    }

    virtual ChannelHandlerContext* createContext(const std::string& name,
        const EventLoopPtr& eventLoop,
        ChannelPipeline& pipeline,
        ChannelHandlerContext* prev,
        ChannelHandlerContext* next) {
            return new ChannelOutboundMessageHandlerContext<OutboundInT>(name,
                eventLoop,
                pipeline,
                shared_from_this(),
                prev,
                next);
    }

protected:
    virtual void flush(OutboundMessageContext& ctx,
        const ChannelFuturePtr& future) {
            ctx.flush(future);
    }
};

}
}

#endif //#if !defined(CETTY_CHANNEL_CHANNELOUTBOUNDMESSAGEHANDLER_H)

// Local Variables:
// mode: c++
// End: