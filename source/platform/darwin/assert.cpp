// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/assert.hpp"

#include <iostream>

namespace Crunch { namespace Detail {

// TODO: Share implementation with linux
bool DefaultAssertHandler(char const* condition, char const* file, int line, char const* message)
{
    std::cerr << "Assertion:" << std::endl;
    std::cerr << "\tLocation: " << file << "[" << line << "]" << std::endl;
    std::cerr << "\tExpression: " << condition << std::endl;
    std::cerr << "\tMessage: " << message << std::endl;
    return true;
}

}}
