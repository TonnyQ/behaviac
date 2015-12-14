/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Tencent is pleased to support the open source community by making behaviac available.
//
// Copyright (C) 2015 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at http://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and limitations under the License.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "behaviac/base/core/thread/wrapper.h"
#include "behaviac/base/core/thread/mutex.h"

#if BEHAVIAC_COMPILER_MSVC
#include <windows.h>

namespace behaviac
{
    namespace Thread
    {
        void Sleep(long millis)
        {
            ::Sleep(millis);
        }
    }

    // Returns a new value of i
    Atomic32 AtomicInc(volatile Atomic32& i)
    {
        return InterlockedIncrement(reinterpret_cast<volatile long*>(&i));
    }

    Atomic32 AtomicDec(volatile Atomic32& i)
    {
        return InterlockedDecrement(reinterpret_cast<volatile long*>(&i));
    }
}
#endif//#if BEHAVIAC_COMPILER_MSVC