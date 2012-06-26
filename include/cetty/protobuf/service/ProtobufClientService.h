#if !defined(CETTY_PROTOBUF_SERVICE_PROTOBUFCLIENTSERVICE_H)
#define CETTY_PROTOBUF_SERVICE_PROTOBUFCLIENTSERVICE_H

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

#include <cetty/service/ClientService.h>
#include <cetty/protobuf/service/ProtobufServiceFuture.h>
#include <cetty/protobuf/service/handler/ProtobufServiceMessagePtr.h>

namespace cetty {
namespace protobuf {
namespace service {

using namespace cetty::service;
using namespace cetty::protobuf::service::handler;

typedef ClientService<ProtobufServiceMessagePtr, MessagePtr> ProtobufClientService;
typedef boost::intrusive_ptr<ProtobufClientService> ProtobufClientServicePtr;

}
}
}

#endif //#if !defined(CETTY_PROTOBUF_SERVICE_PROTOBUFCLIENTSERVICE_H)

// Local Variables:
// mode: c++
// End: