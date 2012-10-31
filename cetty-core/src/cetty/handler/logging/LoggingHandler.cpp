/*
 * Copyright (c) 2010-2011 frankee zhou (frankee.zhou at gmail dot com)
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

#include <cetty/handler/logging/LoggingHandler.h>
#include <cetty/buffer/ChannelBuffer.h>
#include <cetty/channel/Channel.h>
#include <cetty/channel/SocketAddress.h>
#include <cetty/channel/ChannelHandlerContext.h>

#include <cetty/logging/Logger.h>

namespace cetty {
namespace handler {
namespace logging {

using namespace cetty::logging;
using namespace cetty::buffer;
using namespace cetty::channel;


void LoggingHandler::channelCreated(ChannelHandlerContext& ctx) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " CREATED";
    }

    AbstractChannelHandler::channelCreated(ctx);
}

void LoggingHandler::channelActive(ChannelHandlerContext& ctx) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " ACTIVE";
    }

    AbstractChannelHandler::channelActive(ctx);
}

void LoggingHandler::channelInactive(ChannelHandlerContext& ctx) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " INACTIVE";
    }

    AbstractChannelHandler::channelInactive(ctx);
}

void LoggingHandler::exceptionCaught(ChannelHandlerContext& ctx,
                                     const ChannelException& cause) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " EXCEPTION: "
                << cause.getMessage();
    }

    AbstractChannelHandler::exceptionCaught(ctx, cause);
}

void LoggingHandler::userEventTriggered(ChannelHandlerContext& ctx,
                                        const boost::any& evt) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " USER_EVENT: ";
    }

    AbstractChannelHandler::userEventTriggered(ctx, evt);
}

void LoggingHandler::bind(ChannelHandlerContext& ctx,
                          const SocketAddress& localAddress,
                          const ChannelFuturePtr& future) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " BIND("
                << localAddress.toString()
                << ")";
    }

    AbstractChannelHandler::bind(ctx, localAddress, future);
}

void LoggingHandler::connect(ChannelHandlerContext& ctx,
                             const SocketAddress& remoteAddress,
                             const SocketAddress& localAddress,
                             const ChannelFuturePtr& future) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " CONNECT("
                << remoteAddress.toString()
                << ", "
                << localAddress.toString()
                << ")";
    }

    AbstractChannelHandler::connect(ctx, remoteAddress, localAddress, future);
}

void LoggingHandler::disconnect(ChannelHandlerContext& ctx, const ChannelFuturePtr& future) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " DISCONNECT()";
    }

    AbstractChannelHandler::disconnect(ctx, future);
}

void LoggingHandler::close(ChannelHandlerContext& ctx,
                           const ChannelFuturePtr& future) {
    if (Logger::isEnabled(level)) {
        Logger("loggerHander", 0, level).stream()
                << ctx.getChannel()->toString()
                << " CLOSE()";
    }

    AbstractChannelHandler::close(ctx, future);
}

void LoggingHandler::flush(ChannelHandlerContext& ctx,
                           const ChannelFuturePtr& future) {
    ctx.flush(future);
}

void LoggingHandler::messageUpdated(ChannelHandlerContext& ctx) {
    ctx.fireMessageUpdated();
}

}
}
}
