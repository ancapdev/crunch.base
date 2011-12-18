// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_ARCH_X86_CPUID_HPP
#define CRUNCH_BASE_ARCH_X86_CPUID_HPP

#include "crunch/base/api.hpp"
#include "crunch/base/enum_class.hpp"
#include "crunch/base/platform.hpp"
#include <cstdint>

#if !defined (CRUNCH_ARCH_X86)
#   error "Unsupported archicture"
#endif

#include <string>

namespace Crunch {

struct CpuidResult
{
    std::uint32_t eax;
    std::uint32_t ebx;
    std::uint32_t ecx;
    std::uint32_t edx;
};

CRUNCH_ENUM_CLASS CpuidFunction : std::uint32_t
{
    VendorId = 0,
    ProcessorInfoAndFeatures = 1,
    CacheAndTlb = 2,
    SerialNumber = 3,
    HighestExtendedFunction = 0x80000000,
    ExtendedProcessorInfoAndFeatures = 0x80000001,
    ProcessorBrandString1 = 0x80000002,
    ProcessorBrandString2 = 0x80000003,
    ProcessorBrandString3 = 0x80000004,
    LevelOneCacheAndTlbIdentifiers = 0x80000005,
    ExtendedLevelTwoCacheFeaturs = 0x80000006,
    AdvancedPowerManagementInfo = 0x80000007,
    AddressSizes = 0x80000008
};

CRUNCH_BASE_API CpuidResult QueryCpuid(std::uint32_t function, std::uint32_t extendedFunction = 0);

inline CpuidResult QueryCpuid(CpuidFunction function, std::uint32_t extendedFunction = 0)
{
    return QueryCpuid(static_cast<std::uint32_t>(function), extendedFunction);
}

CRUNCH_BASE_API std::string GetCpuidVendorId();
CRUNCH_BASE_API std::uint32_t GetCpuidMaxFunction();

}

#endif
