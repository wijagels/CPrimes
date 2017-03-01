cmake_minimum_required(VERSION 3.0)

project(cprimes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
find_package(GMP REQUIRED)
include_directories(${GMP_INCLUDE_DIR})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
    endif()
endfunction()

# example usage
enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-Werror")
enable_cxx_compiler_flag_if_supported("-pedantic")


add_executable(primes Main.cpp Primes.cpp)
target_link_libraries(primes Threads::Threads ${Boost_LIBRARIES} ${GMP_LIBRARIES} ${GMPXX_LIBRARIES})
