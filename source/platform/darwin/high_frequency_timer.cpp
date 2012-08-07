// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/high_frequency_timer.hpp"

namespace Crunch {

HighFrequencyTimer::HighFrequencyTimer()
{
    mach_timebase_info(&mTimebaseInfo);
    mInvFrequency = 1e-9 * mTimebaseInfo.numer / mTimebaseInfo.denom;
}

HighFrequencyTimer::SampleType HighFrequencyTimer::Sample() const
{
    return mach_absolute_time();
}

Duration HighFrequencyTimer::GetElapsedTime(SampleType begin, SampleType end) const
{
    return Duration::Nanoseconds((end - begin) * mTimebaseInfo.numer / mTimebaseInfo.denom);
}

double HighFrequencyTimer::GetElapsedSeconds(SampleType begin, SampleType end) const
{
    return (end - begin) * mInvFrequency;
}

}
