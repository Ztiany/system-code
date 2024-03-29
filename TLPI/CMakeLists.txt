# 指定 CMake 版本
cmake_minimum_required(VERSION 3.16)

# 指定 C/C++ 标准
set(CMAKE_C_STANDARD 99)

# 项目名称
project(TLPI)

# Put the libaries and binaries that get built into directories at the
# top of the build tree rather than in hard-to-find leaf directories.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

# 包含项目目录下的所有的头文件
include_directories(${PROJECT_SOURCE_DIR})

# check epoll and add config.h for the macro compilation
include(CheckSymbolExists)
check_symbol_exists(epoll_create "sys/epoll.h" EPOLL_EXISTS)
if (EPOLL_EXISTS)
    MESSAGE("epoll is available")
    # Linux下设置为 epoll
    set(EPOLL_ENABLE 1 CACHE INTERNAL "enable epoll")
    # Linux下设置为 poll【测试用】
    # set(EPOLL_ENABLE "" CACHE INTERNAL "not enable epoll")
else ()
    MESSAGE("epoll is not available")
    set(EPOLL_ENABLE "" CACHE INTERNAL "not enable epoll")
endif ()

if (EPOLL_ENABLE)
    MESSAGE("epoll is enabled")
endif ()

# 配置生成头文件
#  CMAKE_CURRENT_BINARY_DIR 指的是工程编译结果存放的目标目录
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)
# 包含生成的头文件
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

add_subdirectory(lib/)
add_subdirectory(chapter47/example)
add_subdirectory(chapter49/example)

