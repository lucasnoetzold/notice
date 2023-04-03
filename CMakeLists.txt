cmake_minimum_required(VERSION 3.23)
project(notice)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_ROOT lib/boost)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.81.0 REQUIRED COMPONENTS log)

add_executable(notice src/main.cpp)
target_link_libraries(notice Qt5::Core Qt5::Gui Qt5::Widgets Boost::log)