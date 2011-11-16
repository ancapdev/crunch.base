// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_RESULT_OF_HPP
#define CRUNCH_RESULT_OF_HPP

#include "crunch/base/declval.hpp"

namespace Crunch
{

template<typename F>
struct ResultOf
{
    typedef decltype(Declval<F>()()) Type;
};

template<typename F, typename A0>
struct ResultOf<F(A0)>
{
    typedef decltype(Declval<F>()(Declval<A0>())) Type;
};

template<typename F, typename A0, typename A1>
struct ResultOf<F(A0, A1)>
{
    typedef decltype(Declval<F>()(Declval<A0>(), Declval<A1>())) Type;
};

template<typename F, typename A0, typename A1, typename A2>
struct ResultOf<F(A0, A1, A2)>
{
    typedef decltype(Declval<F>()(Declval<A0>(), Declval<A1>(), Declval<A2>())) Type;
};

}

#endif
