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

#include <cetty/logging/Logger.h>

#include <cstdio>
#include <cstdlib>

namespace cetty {
namespace logging {

cetty::logging::LogLevel Logger::level = LogLevel::DEBUG;
cetty::logging::LogPatternFormatter Logger::formatter;

Logger::Logger(SourceFile file, int line)
    : message(LogLevel::INFO, file.data, line) {
}

Logger::Logger(SourceFile file, int line, LogLevel level)
    : message(level, file.data, line) {
}

Logger::Logger(SourceFile file, int line, const char* func, LogLevel level)
    : message(level, file.data, line, func) {
}

Logger::Logger(SourceFile file, int line, bool toAbort)
    : message(toAbort ? LogLevel::FATAL : LogLevel::ERROR, file.data, line) {
}

Logger::~Logger() {
    if (message.finish()) {
        const char* buffer = message.getBuffer();
        std::fwrite(buffer, strlen(buffer), 1, stdout);
        //fwrite(msg, 1, len, stdout);

        if (message.getLevel() == LogLevel::FATAL) {
            std::fflush(stdout);
        }
    }
}

}
}
