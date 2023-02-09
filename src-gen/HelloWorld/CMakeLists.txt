cmake_minimum_required(VERSION 3.19)
project(HelloWorld LANGUAGES C)
if(CMAKE_BUILD_TYPE STREQUAL "Test")
  set(CMAKE_BUILD_TYPE "Debug")
  if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    find_program(LCOV_BIN lcov)
    if(LCOV_BIN MATCHES "lcov$")
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -fprofile-arcs -ftest-coverage")
    else()
      message("Not producing code coverage information since lcov was not found")
    endif()
  else()
    message("Not producing code coverage information since the selected compiler is no gcc")
  endif()
endif()
# Require C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(DEFAULT_BUILD_TYPE Release)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE ${DEFAULT_BUILD_TYPE} CACHE STRING "Choose the type of build." FORCE)
endif()
# do not print install messages
set(CMAKE_INSTALL_MESSAGE NEVER)
# Target definitions
add_compile_definitions(LF_REACTION_GRAPH_BREADTH=1)
add_compile_definitions(LF_THREADED=1)
add_compile_definitions(NUMBER_OF_WORKERS=0)
add_compile_definitions(SCHEDULER=NP)
add_compile_definitions(LOG_LEVEL=2)
add_subdirectory(core)
set(LF_MAIN_TARGET HelloWorld)
# Declare a new executable target and list all its sources
add_executable(
    ${LF_MAIN_TARGET}
    lib/schedule.c
    HelloWorld.c
)
target_link_libraries(${LF_MAIN_TARGET} PRIVATE core)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/api)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/platform)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/modal_models)
target_include_directories(${LF_MAIN_TARGET} PUBLIC include/core/utils)
# Find threads and link to it
find_package(Threads REQUIRED)
target_link_libraries(${LF_MAIN_TARGET} PRIVATE Threads::Threads)
# Set the number of workers to enable threading/tracing
target_compile_definitions(${LF_MAIN_TARGET} PUBLIC NUMBER_OF_WORKERS=0)
# Set flag to indicate a multi-threaded runtime
target_compile_definitions( ${LF_MAIN_TARGET} PUBLIC LF_THREADED=1)
    install(
        TARGETS ${LF_MAIN_TARGET}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
