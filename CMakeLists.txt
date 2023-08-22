cmake_minimum_required(VERSION 3.14)
project(Guidelines)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

option(ENABLE_CLANG_TIDY "Enable clang-tidy during compilation" OFF)
set(CLANG_TIDY_EXE "/opt/homebrew/opt/llvm/bin/clang-tidy")
if(NOT EXISTS ${CLANG_TIDY_EXE})
    message(WARNING "clang-tidy not found at ${CLANG_TIDY_EXE}!")
else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
endif()

# Find clang-format
find_program(CLANG_FORMAT_EXE NAMES "clang-format" PATHS "/opt/homebrew/opt/llvm/bin")

# Add clang-format target (if clang-format is found)
if(CLANG_FORMAT_EXE)
    message(STATUS "clang-format found at: ${CLANG_FORMAT_EXE}")
    # Gather all your source files into variable SOURCE_FILES
    file(GLOB_RECURSE SOURCE_FILES 
         ${CMAKE_SOURCE_DIR}/src/*.cpp 
         ${CMAKE_SOURCE_DIR}/src/*.h)

    add_custom_target(
        clang-format
        COMMAND ${CLANG_FORMAT_EXE} -i -style=file ${SOURCE_FILES}
        COMMENT "Running clang-format"
    )
endif()


enable_testing()

add_executable(
  hello_test
  src/cpp/hello_test.cc
)

target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
