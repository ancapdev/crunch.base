// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_HIGH_FREQUENCY_TIMER_HPP
#define CRUNCH_BASE_HIGH_FREQUENCY_TIMER_HPP

#include "crunch/base/api.hpp"
#include "crunch/base/duration.hpp"
#include "crunch/base/platform.hpp"

#if defined (CRUNCH_PLATFORM_WIN32)
#elif defined (CRUNCH_PLATFORM_DARWIN)
#   include <mach/mach_time.h>
#elif defined (CRUNCH_PLATFORM_LINUX)
#   include <time.h>
#else
#   error "Unsupported platform"
#endif

namespace Crunch {

class CRUNCH_BASE_API HighFrequencyTimer
{
public:
#if defined (CRUNCH_PLATFORM_WIN32)
    typedef __int64 SampleType;
    HighFrequencyTimer();
#elif defined (CRUNCH_PLATFORM_DARWIN)
    typedef std::uint64_t SampleType;
    HighFrequencyTimer();
#else
    typedef timespec SampleType;
#endif

    SampleType Sample() const;
    Duration GetElapsedTime(SampleType begin, SampleType end) const;
    double GetElapsedSeconds(SampleType begin, SampleType end) const;
    double GetElapsedMilliseconds(SampleType begin, SampleType end) const;
    double GetElapsedMicroseconds(SampleType begin, SampleType end) const;
    double GetElapsedNanoseconds(SampleType begin, SampleType end) const;

private:
#if defined (CRUNCH_PLATFORM_WIN32)
    __int64 mFrequency;
    double mInvFrequency;
#elif defined (CRUNCH_PLATFORM_DARWIN)
    mach_timebase_info_data_t mTimebaseInfo;
    double mInvFrequency;
#endif
};

inline double HighFrequencyTimer::GetElapsedMilliseconds(SampleType begin, SampleType end) const
{
    return GetElapsedSeconds(begin, end) * 1000.0;
}

inline double HighFrequencyTimer::GetElapsedMicroseconds(SampleType begin, SampleType end) const
{
    return GetElapsedSeconds(begin, end) * 1000000.0;
}

inline double HighFrequencyTimer::GetElapsedNanoseconds(SampleType begin, SampleType end) const
{
    return GetElapsedSeconds(begin, end) * 1000000000.0;
}

}

#endif

