// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_DURATION_HPP
#define CRUNCH_BASE_DURATION_HPP

#include <cstdint>

namespace Crunch {

/// Duration of time
/// Range: +/- 292 years
/// Resolution: 1 nanosecond
class Duration
{
public:
    static Duration Nanoseconds(std::int64_t nanoseconds);
    static Duration Microseconds(std::int64_t microseconds);
    static Duration Milliseconds(std::int64_t milliseconds);
    static Duration Seconds(std::int64_t seconds);
    static Duration Minutes(std::int32_t minutes);
    static Duration Hours(std::int32_t hours);
    static Duration Days(std::int32_t days);

    static Duration const Zero;
    static Duration const PositiveInfinity;
    static Duration const NegativeInfinity;

    std::int64_t GetTotalNanoseconds() const;
    std::int64_t GetTotalMicroseconds() const;
    std::int64_t GetTotalMilliseconds() const;
    std::int64_t GetTotalSeconds() const;
    std::int32_t GetTotalMinutes() const;
    std::int32_t GetTotalHours() const;
    std::int32_t GetTotalDays() const;

    bool IsNegative() const;

    bool operator == (Duration rhs) const;

    Duration& operator += (Duration rhs);
    Duration& operator -= (Duration rhs);

private:
    static std::int64_t const NanosecondsPerMicrosecond = 1000ll;
    static std::int64_t const NanosecondsPerMillisecond = 1000000ll;
    static std::int64_t const NanosecondsPerSecond = 1000000000ll;
    static std::int64_t const NanosecondsPerMinute = 60ll * NanosecondsPerSecond;
    static std::int64_t const NanosecondsPerHour = 60ll * NanosecondsPerMinute;
    static std::int64_t const NanosecondsPerDay = 24 * NanosecondsPerHour;

    Duration(std::int64_t nanoseconds);

    std::int64_t mNanoseconds;
};

inline Duration Duration::Nanoseconds(std::int64_t nanoseconds)
{
    return Duration(nanoseconds);
}

inline Duration Duration::Microseconds(std::int64_t microseconds)
{
    return Duration(microseconds * NanosecondsPerMicrosecond);
}

inline Duration Duration::Milliseconds(std::int64_t milliseconds)
{
    return Duration(milliseconds * NanosecondsPerMillisecond);
}

inline Duration Duration::Seconds(std::int64_t seconds)
{
    return Duration(seconds * NanosecondsPerSecond);
}

inline Duration Duration::Minutes(std::int32_t minutes)
{
    return Duration(minutes * NanosecondsPerMinute);
}

inline Duration Duration::Hours(std::int32_t hours)
{
    return Duration(hours * NanosecondsPerHour);
}

inline Duration Duration::Days(std::int32_t days)
{
    return Duration(days * NanosecondsPerDay);
}

inline std::int64_t Duration::GetTotalNanoseconds() const
{
    return mNanoseconds;
}

inline std::int64_t Duration::GetTotalMicroseconds() const
{
    return mNanoseconds / NanosecondsPerMicrosecond;
}

inline std::int64_t Duration::GetTotalMilliseconds() const
{
    return mNanoseconds / NanosecondsPerMillisecond;
}

inline std::int64_t Duration::GetTotalSeconds() const
{
    return mNanoseconds / NanosecondsPerSecond;
}

inline std::int32_t Duration::GetTotalMinutes() const
{
    return static_cast<std::int32_t>(mNanoseconds / NanosecondsPerMinute);
}

inline std::int32_t Duration::GetTotalHours() const
{
    return static_cast<std::int32_t>(mNanoseconds / NanosecondsPerHour);
}

inline std::int32_t Duration::GetTotalDays() const
{
    return static_cast<std::int32_t>(mNanoseconds / NanosecondsPerDay);
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

inline Duration::Duration(std::int64_t nanoseconds)
    : mNanoseconds(nanoseconds)
{}

inline bool operator < (Duration lhs, Duration rhs)
{
    return lhs.GetTotalNanoseconds() < rhs.GetTotalNanoseconds();
}

inline bool operator > (Duration lhs, Duration rhs)
{
    return lhs.GetTotalNanoseconds() > rhs.GetTotalNanoseconds();
}

inline bool operator <= (Duration lhs, Duration rhs)
{
    return lhs.GetTotalNanoseconds() <= rhs.GetTotalNanoseconds();
}

inline bool operator >= (Duration lhs, Duration rhs)
{
    return lhs.GetTotalNanoseconds() >= rhs.GetTotalNanoseconds();
}

inline bool operator == (Duration lhs, Duration rhs)
{
    return lhs.GetTotalNanoseconds() == rhs.GetTotalNanoseconds();
}

inline bool operator != (Duration lhs, Duration rhs)
{
    return lhs.GetTotalNanoseconds() != rhs.GetTotalNanoseconds();
}

}

#endif
