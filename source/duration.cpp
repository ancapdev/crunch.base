// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/duration.hpp"

namespace Crunch {

const Duration Duration::Zero(0);
//                                          0123456789ABCDEF
const Duration Duration::PositiveInfinity(0x7fffffffffffffffll);
const Duration Duration::NegativeInfinity(0x8000000000000000ll);

}