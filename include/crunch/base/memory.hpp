// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_BASE_MEMORY_HPP
#define CRUNCH_BASE_MEMORY_HPP

#include "crunch/base/platform.hpp"

#include <cstddef>
#if defined (CRUNCH_PLATFORM_DARWIN)
#   include <cstdlib>
#else
#   include <malloc.h>
#endif

namespace Crunch {

inline void* AlignPointerUp(void* pointer, std::size_t alignment)
{
    std::size_t const a = alignment - 1;
    return (void*)(((std::size_t)pointer + a) & ~a);
}

inline void* AlignPointerDown(void* pointer, std::size_t alignment)
{
    return (void*)((std::size_t)pointer & ~(alignment - 1));
}

inline bool IsPointerAligned(void* pointer, std::size_t alignment)
{
    return ((std::size_t)pointer & (alignment - 1)) == 0;
}

inline void* OffsetPointer(void* pointer, std::ptrdiff_t delta)
{
    return (void*)((std::size_t)pointer + delta);
}

#if defined (CRUNCH_PLATFORM_WIN32)

__declspec(noalias) __declspec(restrict) inline void* MallocAligned(std::size_t bytes, std::size_t alignment)
{
    return ::_aligned_malloc(bytes, alignment);
}

__declspec(noalias) inline void FreeAligned(void* allocation)
{
    ::_aligned_free(allocation);
}

#elif defined (CRUNCH_PLATFORM_LINUX)

inline void* MallocAligned(std::size_t bytes, std::size_t alignment)
{
    return ::memalign(alignment, bytes);
}

inline void FreeAligned(void* allocation)
{
    ::free(allocation);
}

#else

inline void* MallocAligned(std::size_t bytes, std::size_t alignment)
{
    void* allocation = std::malloc(bytes + (alignment - 1) + sizeof(void*));
    if (!allocation)
	return NULL;

    void* alignedAllocation = AlignPointerUp(OffsetPointer(allocation, sizeof(void*)),  alignment);
    ((void**)alignedAllocation)[-1] = allocation;

    return alignedAllocation;
}

inline void FreeAligned(void* allocation)
{
    std::free(((void**)allocation)[-1]);
}

#endif

}

#endif
