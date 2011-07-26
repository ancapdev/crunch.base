// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#include "crunch/concurrency/semaphore.hpp"

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test_suite.hpp>

namespace Crunch { namespace Concurrency {

BOOST_AUTO_TEST_SUITE(SemaphoreTests)

BOOST_AUTO_TEST_CASE(InitialReadyThenWaitTest)
{
    Semaphore s(1);
    volatile bool acquired = false;
    s.AddWaiter([&] { acquired = true; });
    BOOST_CHECK(acquired);
}

BOOST_AUTO_TEST_CASE(WaitThenPostTest)
{
    Semaphore s(0);
    volatile bool acquired = false;
    s.AddWaiter([&] { acquired = true; });
    BOOST_CHECK(!acquired);
    s.Post();
    BOOST_CHECK(acquired);
}

BOOST_AUTO_TEST_CASE(PostThenWaitTest)
{
    Semaphore s(0);
    volatile bool acquired = false;
    s.Post();
    s.AddWaiter([&] { acquired = true; });
    BOOST_CHECK(acquired);
}

BOOST_AUTO_TEST_CASE(RemoveWaitFromEmptyTest)
{
    Semaphore s(0);
    
    struct WaitHelper
    {
        static void Do(void*) {}
    };

    DestroyableWaiter* waiter = DestroyableWaiter::Create(&WaitHelper::Do, nullptr);
    BOOST_CHECK(!s.RemoveWaiter(waiter));
    waiter->Destroy();
}

BOOST_AUTO_TEST_CASE(RemoveWaiterTest)
{
    Semaphore s(0);

    struct WaitHelper
    {
        static void Do(void*) {}
    };

    DestroyableWaiter* waiter = DestroyableWaiter::Create(&WaitHelper::Do, nullptr);
    s.AddWaiter(waiter);
    BOOST_CHECK(s.RemoveWaiter(waiter));
    waiter->Destroy();
}

BOOST_AUTO_TEST_SUITE_END()

}}