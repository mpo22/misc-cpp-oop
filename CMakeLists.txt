cmake_minimum_required(VERSION 3.23)

# https://cmake.org/cmake/help/latest/prop_tgt/C_STANDARD.html
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
project(misc-cpp-oop LANGUAGES CXX)

find_package(Catch2)
find_package(spdlog)
find_package(trompeloeil)

add_executable(${PROJECT_NAME}
        src/catch2_helper.cpp
        src/delegatee.cpp
        src/delegatee_impl1.cpp
        src/delegatee_impl1.cpp
        src/delegator.cpp
        src/libfmt_helper.cpp
        src/service.cpp
        src/spdlog_helper.cpp
        src/delegator_test.cpp
        src/trompeloeil_test.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} Catch2::Catch2WithMain spdlog::spdlog trompeloeil::trompeloeil)

include(CTest)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
