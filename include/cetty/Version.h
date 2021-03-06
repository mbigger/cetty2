#if !defined(CETTY_VERSION_H)
#define CETTY_VERSION_H

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

//
// Version Information
//
// Version format is 0xAABBCC, where
//    - AA is the major version number,
//    - BB is the minor version number,
//    - CC is the revision number.

#define CETTY_VERSION 0x000803

#define CETTY_VERSION_MAJOR    ( CETTY_VERSION >> 16 )
#define CETTY_VERSION_MINOR    ((CETTY_VERSION & 0xff00) >> 8)
#define CETTY_VERSION_REVISION ( CETTY_VERSION & 0xff )

#endif //#if !defined(CETTY_VERSION_H)

// Local Variables:
// mode: c++
// End:
