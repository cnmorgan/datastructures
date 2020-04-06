cmake_minimum_required(VERSION 3.1)

include(CTest)

#-----------------#
# CMake Variables #
#-----------------#

set(TARGET_NAME datastructures)

# Add all src/*.cpp files
set(SOURCES 
)

# Add all tests/*.cpp files
set(TEST_SOURCES
    tests/main.cpp
    tests/list.cpp
    tests/linked_list.cpp
    tests/stack.cpp
)

#project(${TARGET_NAME} VERSION 1.0.0 LANGUAGES CXX)

# Create Library
#add_library(${TARGET_NAME} SHARED ${SOURCES})

# include files
# TODO: Add 3rd party includes here e.g. ./libs/LIB_NAME/include
#target_include_directories(${TARGET_NAME} PRIVATE ./include)

# Create executable for tests
add_executable(tests ${TEST_SOURCES})

target_include_directories(tests PRIVATE ./include)

add_test(NAME tests COMMAND tests)
enable_testing()

# Create Executable
#add_executable(main app/main.cpp)
#target_link_libraries(main PRIVATE ${TARGET_NAME})

# external libraries
# TODO: Add library references when needed
#add_subdirectory(libs/example)
#target_link_libraries(${TARGET_NAME} PUBLIC example)
