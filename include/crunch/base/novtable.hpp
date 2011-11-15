// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_NOVTABLE_HPP
#define CRUNCH_BASE_NOVTABLE_HPP

#include "crunch/base/platform.hpp"

#if defined (CRUNCH_COMPILER_MSVC)
#   define CRUNCH_NOVTABLE __declspec(novtable)
#elif defined (CRUNCH_COMPILER_GCC)
#   define CRUNCH_NOVTABLE
#else
#   error "Unsupported compiler"
#endif

#endif
