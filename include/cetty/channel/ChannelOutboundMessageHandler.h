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

#include <cetty/channel/ChannelOutboundMessageHandlerFwd.h>
#include <cetty/channel/ChannelOutboundMessageHandlerContext.h>

namespace cetty {
namespace channel {

template<typename OutboundInT> inline
ChannelHandlerContext* ChannelOutboundMessageHandler<OutboundInT>::createContext(const std::string& name,
        ChannelPipeline& pipeline,
        ChannelHandlerContext* prev,
        ChannelHandlerContext* next) {
    return new ChannelOutboundMessageHandlerContext<OutboundInT>(name,
            pipeline,
            shared_from_this(),
            prev,
            next);
}

template<typename OutboundInT> inline
ChannelHandlerContext* ChannelOutboundMessageHandler<OutboundInT>::createContext(const std::string& name,
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

}
}

#endif //#if !defined(CETTY_CHANNEL_CHANNELOUTBOUNDMESSAGEHANDLER_H)

// Local Variables:
// mode: c++
// End:
