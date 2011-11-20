// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_NOEXCEPT_HPP
#define CRUNCH_BASE_NOEXCEPT_HPP

#include "crunch/base/platform.hpp"

#if defined (CRUNCH_COMPILER_GCC)
#   define CRUNCH_NOEXCEPT noexcept
#else
#   define CRUNCH_NOEXCEPT throw()
#endif

#endif
