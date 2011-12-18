// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_EXCEPTION_HPP
#define CRUNCH_BASE_EXCEPTION_HPP

#include "crunch/base/api.hpp"
#include "crunch/base/noexcept.hpp"
#include "crunch/base/override.hpp"

#include <exception>
#include <string>

namespace Crunch {

class CRUNCH_BASE_API Exception : public std::exception
{
public:
    Exception(std::string const& message);

    ~Exception() CRUNCH_NOEXCEPT;

    char const* what() const CRUNCH_NOEXCEPT CRUNCH_OVERRIDE;

private:
    std::string mMessage;
};

}

#endif
