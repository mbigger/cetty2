#if !defined(CETTY_REDIS_PROTOCOL_COMMAND_TRANSACTIONS_H)
#define CETTY_REDIS_PROTOCOL_COMMAND_TRANSACTIONS_H

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

#include <string>
#include <cetty/util/StringPiece.h>
#include <cetty/redis/protocol/RedisCommand.h>

namespace cetty {
namespace redis {
namespace protocol {
namespace commands {

using namespace cetty::redis;

RedisCommandPtr transactionsCommandDiscard();
RedisCommandPtr transactionsCommandExec();
RedisCommandPtr transactionsCommandMulti();

RedisCommandPtr transactionsCommandUnwatch();
RedisCommandPtr transactionsCommandWatch(const std::string& key);

extern const std::string WATCH;

template<typename Iterator>
RedisCommandPtr transactionsCommandWatch(const Iterator& begin,
        const Iterator& end) {
    RedisCommandPtr command(new RedisCommand(WATCH));

    for (Iterator itr = begin; itr != end; ++itr) {
        (*command) << *itr;
    }

    command->done();
    return command;
}

}
}
}
}

#endif //#if !defined(CETTY_REDIS_PROTOCOL_COMMAND_TRANSACTIONS_H)

// Local Variables:
// mode: c++
// End: