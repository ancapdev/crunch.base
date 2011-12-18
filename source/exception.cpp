// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/exception.hpp"

namespace Crunch {

Exception::Exception(std::string const& message)
    : mMessage(message)
{}

Exception::~Exception() CRUNCH_NOEXCEPT
{}

char const* Exception::what() const CRUNCH_NOEXCEPT
{
    return mMessage.c_str();
}

}
