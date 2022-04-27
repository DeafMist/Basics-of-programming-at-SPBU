cmake_minimum_required(VERSION 3.17)

project(Moiseev)

set(SOURCES
        Semester2/exam.cpp)

add_executable(Moiseev ${SOURCES})

set_target_properties(
        Moiseev PROPERTIES
        CXX_VERSION 17
        CXX_VERSION_REQUIRED ON
)