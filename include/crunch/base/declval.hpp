// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_DECLVAL_HPP
#define CRUNCH_DECLVAL_HPP

#include <type_traits>

namespace Crunch
{

template<typename T>
typename std::add_rvalue_reference<T>::type Declval()
{
    return *(T*)0;
}

}

#endif
