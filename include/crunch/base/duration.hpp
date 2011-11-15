// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_DURATION_HPP
#define CRUNCH_BASE_DURATION_HPP

#include "crunch/base/stdint.hpp"

namespace Crunch {

/// Duration of time
/// Range: +/- 292 years
/// Resolution: 1 nanosecond
class Duration
{
public:
    static Duration Nanoseconds(int64 nanoseconds);
    static Duration Microseconds(int64 microseconds);
    static Duration Milliseconds(int64 milliseconds);
    static Duration Seconds(int64 seconds);
    static Duration Minutes(int32 minutes);
    static Duration Hours(int32 hours);
    static Duration Days(int32 days);

    static Duration const Zero;
    static Duration const PositiveInfinity;
    static Duration const NegativeInfinity;

    int64 GetTotalNanoseconds() const;
    int64 GetTotalMicroseconds() const;
    int64 GetTotalMilliseconds() const;
    int64 GetTotalSeconds() const;
    int32 GetTotalMinutes() const;
    int32 GetTotalHours() const;
    int32 GetTotalDays() const;

    bool IsNegative() const;

    bool operator == (Duration rhs) const;

    Duration& operator += (Duration rhs);
    Duration& operator -= (Duration rhs);

private:
    static int64 const NanosecondsPerMicrosecond = 1000ll;
    static int64 const NanosecondsPerMillisecond = 1000000ll;
    static int64 const NanosecondsPerSecond = 1000000000ll;
    static int64 const NanosecondsPerMinute = 60ll * NanosecondsPerSecond;
    static int64 const NanosecondsPerHour = 60ll * NanosecondsPerMinute;
    static int64 const NanosecondsPerDay = 24 * NanosecondsPerHour;

    Duration(int64 nanoseconds);

    int64 mNanoseconds;
};

inline Duration Duration::Nanoseconds(int64 nanoseconds)
{
    return Duration(nanoseconds);
}

inline Duration Duration::Microseconds(int64 microseconds)
{
    return Duration(microseconds * NanosecondsPerMicrosecond);
}

inline Duration Duration::Milliseconds(int64 milliseconds)
{
    return Duration(milliseconds * NanosecondsPerMillisecond);
}

inline Duration Duration::Seconds(int64 seconds)
{
    return Duration(seconds * NanosecondsPerSecond);
}

inline Duration Duration::Minutes(int32 minutes)
{
    return Duration(minutes * NanosecondsPerMinute);
}

inline Duration Duration::Hours(int32 hours)
{
    return Duration(hours * NanosecondsPerHour);
}

inline Duration Duration::Days(int32 days)
{
    return Duration(days * NanosecondsPerDay);
}

inline int64 Duration::GetTotalNanoseconds() const
{
    return mNanoseconds;
}

inline int64 Duration::GetTotalMicroseconds() const
{
    return mNanoseconds / NanosecondsPerMicrosecond;
}

inline int64 Duration::GetTotalMilliseconds() const
{
    return mNanoseconds / NanosecondsPerMillisecond;
}

inline int64 Duration::GetTotalSeconds() const
{
    return mNanoseconds / NanosecondsPerSecond;
}

inline int32 Duration::GetTotalMinutes() const
{
    return static_cast<int32>(mNanoseconds / NanosecondsPerMinute);
}

inline int32 Duration::GetTotalHours() const
{
    return static_cast<int32>(mNanoseconds / NanosecondsPerHour);
}

inline int32 Duration::GetTotalDays() const
{
    return static_cast<int32>(mNanoseconds / NanosecondsPerDay);
}

inline bool Duration::IsNegative() const
{
    return mNanoseconds < 0;
}

inline bool Duration::operator == (Duration rhs) const
{
    return mNanoseconds == rhs.mNanoseconds;
}

inline Duration& Duration::operator += (Duration rhs)
{
    mNanoseconds += rhs.mNanoseconds;
    return *this;
}

inline Duration& Duration::operator -= (Duration rhs)
{
    mNanoseconds -= rhs.mNanoseconds;
    return *this;
}

inline Duration operator + (Duration lhs, Duration rhs)
{
    return lhs += rhs;
}

inline Duration operator - (Duration lhs, Duration rhs)
{
    return lhs -= rhs;
}

inline Duration::Duration(int64 nanoseconds)
    : mNanoseconds(nanoseconds)
{}

}

#endif
