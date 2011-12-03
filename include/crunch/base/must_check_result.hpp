// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_MUST_CHECK_RESULT_HPP
#define CRUNCH_BASE_MUST_CHECK_RESULT_HPP

#include "crunch/base/platform.hpp"

#if defined (CRUNCH_COMPILER_GCC)
#   define CRUNCH_MUST_CHECK_RESULT __attribute__((warn_unused_result))
#elif defined (CRUNCH_COMPILER_MSVC) && (CRUNCH_PTR_SIZE == 4)
#   include <CodeAnalysis/SourceAnnotations.h>
    using namespace vc_attributes;
#   define CRUNCH_MUST_CHECK_RESULT [returnvalue:Post(MustCheck=Yes)]
#else
#   define CRUNCH_MUST_CHECK_RESULT
#endif

#endif
