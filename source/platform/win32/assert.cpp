// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/base/assert.hpp"

#include <cstdio>

#include <Windows.h>

// Merely a convenient place to put Visual Leak Detector include
// assert.cpp is very unlikely to be unreferenced
#if defined (CRUNCH_VLD_ENABLED)
#   include <vld.h>
#endif

namespace Crunch { namespace Detail {

bool DefaultAssertHandler(char const* condition, char const* file, int line, char const* message)
{
    char buffer[4096];

    sprintf_s(
        buffer,
        "Location:\t\t%s [%d]\n"
        "Expression:\t%s\n"
        "Message:\t\t%s\n\n\n"
        "Press Abort to quit, Retry to debug, or Ignore to continue",
        file,
        line,
        condition ? condition : "<No condition>",
        message ? message : "<No message>");

    int mbResult = MessageBoxA(
        NULL,
        buffer,
        "Assert",
        MB_ABORTRETRYIGNORE | MB_ICONERROR | MB_SETFOREGROUND);

    switch (mbResult)
    {
    case IDIGNORE:
        return false;

    case IDABORT:
        std::exit(-1);
    
    default:
        return true;
    }
}

}}