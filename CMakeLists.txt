cmake_minimum_required(VERSION 3.10)
project(metrics_agent)

set(CMAKE_CXX_STANDARD 17)

add_executable(metrics-agent src/main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(metrics-agent PRIVATE Threads::Threads)

