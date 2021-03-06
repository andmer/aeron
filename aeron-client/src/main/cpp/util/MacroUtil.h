/*
 * Copyright 2014-2019 Real Logic Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef AERON_UTIL_MACRO_UTIL_FILE_H
#define AERON_UTIL_MACRO_UTIL_FILE_H

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#define CONCAT_SYMBOLS(x, y) x##y

namespace aeron { namespace util {

inline static constexpr std::int32_t semanticVersionCompose(
    std::uint8_t major, std::uint8_t minor, std::uint8_t patch) noexcept
{
    return (major << 16) | (minor << 8) | patch;
}

}}

#if COND_MOCK == 1
    #define COND_MOCK_VIRTUAL virtual
#else
    #define COND_MOCK_VIRTUAL
#endif

#if defined(__GNUC__)
    #define AERON_COND_EXPECT(exp,c) (__builtin_expect((exp),c))
#else
    #define AERON_COND_EXPECT(exp,c) (exp)
#endif

#endif
