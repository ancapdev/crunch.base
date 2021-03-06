# Copyright (c) 2011-2013, Christian Rorvik
# Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

vpm_depend_self()

if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86" OR
    ${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
  set(_platformFiles
    include/crunch/base/arch/x86/cpuid.hpp
    source/arch/x86/cpuid.cpp)
endif()

if(WIN32)
  list(APPEND _platformFiles include/crunch/base/platform/win32/wintypes.hpp)
endif()

vpm_add_library(crunch_base_lib
  include/crunch/base/align.hpp
  include/crunch/base/api.hpp
  include/crunch/base/assert.hpp
  include/crunch/base/bit_utility.hpp
  include/crunch/base/debug.hpp
  include/crunch/base/declval.hpp
  include/crunch/base/duration.hpp
  include/crunch/base/exception.hpp
  include/crunch/base/enum_class.hpp
  include/crunch/base/high_frequency_timer.hpp
  include/crunch/base/ignore_result.hpp
  include/crunch/base/inline.hpp
  include/crunch/base/intrusive_ptr.hpp
  include/crunch/base/memory.hpp
  include/crunch/base/must_check_result.hpp
  include/crunch/base/noexcept.hpp
  include/crunch/base/noncopyable.hpp
  include/crunch/base/noreturn.hpp
  include/crunch/base/novtable.hpp
  include/crunch/base/override.hpp
  include/crunch/base/platform.hpp
  include/crunch/base/result_of.hpp
  include/crunch/base/stack_alloc.hpp
  include/crunch/base/stream_as_binary.hpp
  source/assert.cpp
  source/duration.cpp
  source/exception.cpp
  source/platform/${VPM_PLATFORM_NAME}/assert.cpp
  source/platform/${VPM_PLATFORM_NAME}/high_frequency_timer.cpp
  ${_platformFiles})

if(UNIX AND NOT APPLE)
  target_link_libraries(crunch_base_lib rt)
endif()

if(VPM_CURRENT_PACKAGE_IS_ROOT)
  vpm_set_default_version(crunch.test master)
  vpm_depend(crunch.test)

  crunch_add_test(crunch_base_test
    test/intrusive_ptr_tests.cpp
    test/memory_tests.cpp)

  target_link_libraries(crunch_base_test
    crunch_base_lib)
endif()
