cmake_minimum_required(VERSION 3.8)
project(pixelfell VERSION 0.0.1 LANGUAGES C CXX)
project(sandbox LANGUAGES C CXX)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")

find_package(glfw3 REQUIRED)


set(EXT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/src")
set(EXT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/include")
add_library(glad "${EXT_INCLUDE_DIR}/glad/glad.h" "${EXT_SOURCE_DIR}/glad.c")
target_include_directories(glad PUBLIC ${EXT_INCLUDE_DIR})

add_library(pixelfell SHARED 
src/PixelFell/Core.cpp)

set_target_properties(pixelfell PROPERTIES PUBLIC_HEADER src/PixelFell/Core.h)

add_executable(sandbox "src/Sandbox/Sandbox.cpp")
target_include_directories(sandbox PUBLIC .)

target_include_directories(pixelfell PUBLIC .)



target_link_libraries(pixelfell PUBLIC glfw glad PRIVATE ${CMAKE_DL_LIBS})
target_link_libraries(sandbox PUBLIC pixelfell PRIVATE ${CMAKE_DL_LIBS})
