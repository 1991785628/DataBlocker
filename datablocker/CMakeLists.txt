cmake_minimum_required(VERSION 3.10)
project(traffic_firewall)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)

include_directories(include)

add_executable(firewall
    src/main.cpp
    src/server.cpp
    src/session.cpp
)

target_link_libraries(firewall
    Boost::system
    pthread
)