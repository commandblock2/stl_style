set(PROJECT_UNIT_TESTS_NAME ${PROJECT_NAME_STR}_unit_tests)
project(${PROJECT_UNIT_TESTS_NAME} LANGUAGES CXX)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

file(GLOB TEST_SRC *.cpp)
    
add_executable(${PROJECT_UNIT_TESTS_NAME} ${TEST_SRC})
target_include_directories(${PROJECT_UNIT_TESTS_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_include_directories(${PROJECT_UNIT_TESTS_NAME} PRIVATE test/)


add_test(DemoTest ${PROJECT_UNIT_TESTS_NAME})
