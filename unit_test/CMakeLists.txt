cmake_minimum_required(VERSION 3.16)
project(ExampleProjectTest)

set (SOURCE main_unit.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

# set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_subdirectory(src)

enable_testing()

add_subdirectory(googletest)


add_subdirectory(unit_test)


# cmake_minimum_required(VERSION 3.7)
# project(tests)

# add_subdirectory(lib/googletest)

# enable_testing()

# include_directories(${gtest_SOURCE_DIR_}/include ${gtest_SOURCE_DIR_})

# set(SOURCE_FILES
# gtest.cpp
# tests/components/ColorTests.cpp)

# add_executable(tests_run gtest.cpp)

# target_link_libraries(tests_run gtest gtest_main)

# add_test(eq tests_run)
