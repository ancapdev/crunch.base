// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/arch/x86/cpuid.hpp"

#if defined (CRUNCH_COMPILER_MSVC)
    extern "C" void __cpuidex(int a[4], int b, int c);
#   pragma intrinsic(__cpuidex)
#endif

namespace Crunch {

CpuidResult QueryCpuid(std::uint32_t function, std::uint32_t extendedFunction)
{
#if defined (CRUNCH_COMPILER_MSVC)
    int temp[4];
    __cpuidex(temp, static_cast<int>(function), static_cast<int>(extendedFunction));
    CpuidResult const result =
    {
        static_cast<std::uint32_t>(temp[0]),
        static_cast<std::uint32_t>(temp[1]),
        static_cast<std::uint32_t>(temp[2]),
        static_cast<std::uint32_t>(temp[3])
    };
    return result;
#elif defined (CRUNCH_COMPILER_GCC)
    CpuidResult result;
    asm volatile(
        "cpuid"
        : "=a"(result.eax), "=b"(result.ebx), "=c"(result.ecx), "=d"(result.edx)
        : "a"(function), "c"(extendedFunction));
    return result;
#else
#   error "Unsupported compiler"
#endif
}

std::string GetCpuidVendorId()
{
    CpuidResult vendor = QueryCpuid(CpuidFunction::VendorId);

    std::string result;

    for (int i = 0; i < 4; ++i)
        result.push_back(static_cast<char>((vendor.ebx >> (i * 8)) & 0xff));

    for (int i = 0; i < 4; ++i)
        result.push_back(static_cast<char>((vendor.edx >> (i * 8)) & 0xff));

    for (int i = 0; i < 4; ++i)
        result.push_back(static_cast<char>((vendor.ecx >> (i * 8)) & 0xff));

    return result;
}

std::uint32_t GetCpuidMaxFunction()
{
    return QueryCpuid(CpuidFunction::VendorId).eax;
}

}
