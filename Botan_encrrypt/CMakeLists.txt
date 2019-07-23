cmake_minimum_required(VERSION 3.13)
project(Assignment_4)
set(CMAKE_CXX_STANDARD 17)
add_executable(Assignment_4 main.cpp Hashing.cpp Hashing.h)
# Botan Setup
include(ExternalProject)
if (CMAKE_COMPILER_IS_GNUCXX)
    set(botan_cc
            --cc=gcc
            --cc-bin=${CMAKE_CXX_COMPILER}
            )
else ()
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(botan_cc
                --cc=clang
                --cc-bin=${CMAKE_CXX_COMPILER}
                )
    endif ()
endif ()

set(botan_args
        --minimized-build
        --enable-modules=hash,bcrypt,scrypt,hex,auto_rng,system_rng
        --disable-shared
        --prefix=${CMAKE_CURRENT_BINARY_DIR}/botan
        )

ExternalProject_Add(botan_project
        GIT_REPOSITORY https://github.com/randombit/botan.git
        GIT_TAG 2.9.0
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND "" # Don't need to update since using tagged release
        CONFIGURE_COMMAND python configure.py ${botan_cc} ${botan_args}
        BUILD_COMMAND make
        BUILD_BYPRODUCTS ${CMAKE_CURRENT_BINARY_DIR}/botan/lib/libbotan-2.a
        )

add_library(botan STATIC IMPORTED GLOBAL)
add_dependencies(botan botan_project)
set_property(TARGET botan PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/botan/lib/libbotan-2.a)

# Workaround for INTERFACE_INCLUDE_DIRECTORIES. The problem is the include
# directory needs to exist at cmake configuration time even though it won't
# exist until the external project is checked out at build time.
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/botan/include/botan-2)

set_property(TARGET botan PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}/botan/include/botan-2)

target_link_libraries(Assignment_4 botan)

add_subdirectory(tests)