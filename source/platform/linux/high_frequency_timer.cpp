// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/high_frequency_timer.hpp"

namespace Crunch {

HighFrequencyTimer::SampleType HighFrequencyTimer::Sample() const
{
    timespec sample;
    clock_gettime(CLOCK_MONOTONIC, &sample);
    return sample;
}

Duration HighFrequencyTimer::GetElapsedTime(SampleType begin, SampleType end) const
{
    return
        Duration::Seconds(difftime(end.tv_sec, begin.tv_sec)) + 
        Duration::Nanoseconds(end.tv_nsec - begin.tv_nsec);
}

double HighFrequencyTimer::GetElapsedSeconds(SampleType begin, SampleType end) const
{
    return difftime(end.tv_sec, begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
}

}
