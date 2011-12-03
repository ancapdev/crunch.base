// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/high_frequency_timer.hpp"

#include <windows.h>

namespace Crunch {

HighFrequencyTimer::HighFrequencyTimer()
{
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    mFrequency = frequency.QuadPart;
    mInvFrequency = 1.0 / static_cast<double>(mFrequency);
}

HighFrequencyTimer::SampleType HighFrequencyTimer::Sample() const
{
    LARGE_INTEGER sample;
    QueryPerformanceCounter(&sample);
    return sample.QuadPart;
}

Duration HighFrequencyTimer::GetElapsedTime(SampleType begin, SampleType end) const
{
    return Duration::Nanoseconds(((end - begin) * 1000000000ll) / mFrequency);
}

double HighFrequencyTimer::GetElapsedSeconds(SampleType begin, SampleType end) const
{
    return static_cast<double>(end - begin) * mInvFrequency;
}

}
