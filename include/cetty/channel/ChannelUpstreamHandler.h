#if !defined(CETTY_CHANNEL_CHANNELUPSTREAMHANDLER_H)
#define CETTY_CHANNEL_CHANNELUPSTREAMHANDLER_H

/*
 * Copyright 2009 Red Hat, Inc.
 *
 * Red Hat licenses this file to you under the Apache License, version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at:
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */
/*
 * Copyright (c) 2010-2011 frankee zhou (frankee.zhou at gmail dot com)
 * Distributed under under the Apache License, version 2.0 (the "License").
 */

#include <cetty/channel/ChannelHandler.h>

namespace cetty {
namespace channel {

class ChannelEvent;
class MessageEvent;
class ExceptionEvent;
class WriteCompletionEvent;
class ChannelStateEvent;
class ChildChannelStateEvent;

class ChannelHandlerContext;

/**
 * Handles or intercepts an upstream {@link ChannelEvent}, and sends a
 * {@link ChannelEvent} to the next handler in a {@link ChannelPipeline}.
 * <p>
 * The most common use case of this interface is to intercept an I/O event
 * generated by I/O workers to transform the received messages or execute
 * the relevant business logic.
 *
 * <h3>{@link SimpleChannelUpstreamHandler}</h3>
 * <p>
 * In most cases, you will get to use a {@link SimpleChannelUpstreamHandler} to
 * implement an upstream handler because it provides an individual handler
 * method for each event type.  You might want to implement this interface
 * directly though if you want to handle various types of events in more
 * generic way.
 *
 * <h3>Firing an event to the next handler</h3>
 * <p>
 * You can forward the received event upstream or downstream.  In most cases,
 * {@link ChannelUpstreamHandler} will send the event upstream (i.e. inbound)
 * although it is legal to send the event downstream (i.e. outbound):
 *
 * <pre>
 * // Sending the event upstream (inbound)
 * void handleUpstream({@link ChannelHandlerContext} ctx, {@link ChannelEvent} e) throws Exception {
 *     ...
 *     ctx.sendUpstream(e);
 *     ...
 * }
 *
 * // Sending the event downstream (outbound)
 * void handleDownstream({@link ChannelHandlerContext} ctx, {@link ChannelEvent} e) throws Exception {
 *     ...
 *     ctx.sendDownstream(new {@link DownstreamMessageEvent}(...));
 *     ...
 * }
 * </pre>
 *
 * <h4>Using the helper class to send an event</h4>
 * <p>
 * You will also find various helper methods in {@link Channels} to be useful
 * to generate and send an artificial or manipulated event.
 *
 * <h3>State management</h3>
 *
 * Please refer to {@link ChannelHandler}.
 *
 * <h3>Thread safety</h3>
 * <p>
 * {@link #handleUpstream(ChannelHandlerContext, ChannelEvent) handleUpstream}
 * will be invoked sequentially by the same thread (i.e. an I/O thread) and
 * therefore a handler does not need to worry about being invoked with a new
 * upstream event before the previous upstream event is finished.
 * <p>
 * This does not necessarily mean that there's a dedicated thread per
 * {@link Channel}; the I/O thread of some transport can serve more than one
 * {@link Channel} (e.g. NIO transport), while the I/O thread of other
 * transports can serve only one (e.g. OIO transport).
 * <p>
 * However, if you add an {@link ExecutionHandler} to a {@link ChannelPipeline},
 * this behavior changes depending on what {@link Executor} was employed to
 * dispatch the events.  Please refer to {@link ExecutionHandler} for more
 * information.
 *
 *
 * @author <a href="http://gleamynode.net/">Trustin Lee</a>
 * @author <a href="mailto:frankee.zhou@gmail.com">Frankee Zhou</a>
 */

class ChannelUpstreamHandler : virtual public ChannelHandler {
public:
    ChannelUpstreamHandler(){}
    virtual ~ChannelUpstreamHandler() {}

    /**
     * Handles the specified upstream event, except MessageEvent, ExceptionEvent,
     * WriteCompletionEvent, ChannelStateEvent and ChildChannelStateEvent.
     *
     * @param ctx  the context object for this handler
     * @param e    the upstream event to process or intercept
     */
    virtual void handleUpstream(ChannelHandlerContext& ctx, const ChannelEvent& e) = 0;

    /**
     * Invoked when a message object (e.g: {@link ChannelBuffer}) was received
     * from a remote peer.
     */
    virtual void messageReceived(ChannelHandlerContext& ctx, const MessageEvent& e) = 0;

    /**
     * Invoked when an exception was raised by an I/O thread or a
     * {@link ChannelHandler}.
     */
    virtual void exceptionCaught(ChannelHandlerContext& ctx, const ExceptionEvent& e) = 0;

    /**
     * Invoked when something was written into a {@link Channel}.
     */
    virtual void writeCompleted(ChannelHandlerContext& ctx, const WriteCompletionEvent& e) = 0;

    /**
     * Invoked when a {@link Channel}'s state has been changed.
     */
    virtual void channelStateChanged(ChannelHandlerContext& ctx, const ChannelStateEvent& e) =0;

    /**
     * Invoked when a child {@link Channel}'s state  has been changed.
     * (e.g. a server channel accepted a connection, or the accepted connection closed)
     */
    virtual void childChannelStateChanged(ChannelHandlerContext& ctx, const ChildChannelStateEvent& e) = 0;

private:
    ChannelUpstreamHandler(const ChannelUpstreamHandler&);
    ChannelUpstreamHandler& operator=(const ChannelUpstreamHandler&);
};

}
}


#endif //#if !defined(CETTY_CHANNEL_CHANNELUPSTREAMHANDLER_H)

// Local Variables:
// mode: c++
// End:
