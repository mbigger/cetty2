#if !defined(CETTY_CONFIG_KEYVALUEPAIR_H)
#define CETTY_CONFIG_KEYVALUEPAIR_H

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

#include <cetty/config/ConfigObject.h>

namespace cetty {
namespace config {

class KeyValuePair : public ConfigObject {
public:
    static const std::string NAME;

public:
    std::string key;
    std::string value;

    KeyValuePair();
    KeyValuePair(const KeyValuePair& keyValuePair) {
        copyFrom(keyValuePair);
    }

    KeyValuePair& operator=(const KeyValuePair& keyValuePair) {
        copyFrom(keyValuePair);
    }

    virtual ConfigObject* create() const { return new KeyValuePair; }
};

}
}

#endif //#if !defined(CETTY_CONFIG_KEYVALUEPAIR_H)

// Local Variables:
// mode: c++
// End:
