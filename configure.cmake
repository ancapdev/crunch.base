# Copyright (c) 2011, Christian Rorvik
# Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

vpm_include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

if(WIN32)
  # Check if Visual Leak Detector is installed
  if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
    set(_vldLibDir "Win32")
  else()
    set(_vldLibDir "Win64")
  endif()
  find_path(_vldHeaderPath "vld.h" PATHS "$ENV{PROGRAMFILES}/Visual Leak Detector/include")
  find_path(_vldLibPath "vld.lib" PATHS "$ENV{PROGRAMFILES}/Visual Leak Detector/lib/${_vldLibDir}")
  if(NOT ${_vldHeaderPath} STREQUAL _vldHeaderPath-NOTFOUND)
    if(NOT ${_vldLibPath} STREQUAL _vldLibPath-NOTFOUND)
      include_directories(${_vldHeaderPath})
      link_directories(${_vldLibPath})
      set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DCRUNCH_VLD_ENABLED")
    endif()
  endif()
endif()

