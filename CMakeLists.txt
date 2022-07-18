cmake_minimum_required(VERSION 3.16)
project(BUAAEntrance)

set(CMAKE_CXX_STANDARD 14)

include_directories(DataStruct/CSKaoYan)
include_directories(DataStruct/TextBook)

add_executable(BUAAEntrance
        DataStruct/CSKaoYan/CSKaoyan.hpp
        DataStruct/CSKaoYan/Graph.cpp
        DataStruct/TextBook/2_LinearLinkList.cpp
        DataStruct/TextBook/2_LinearLinkList.hpp
        DataStruct/TextBook/2_LinearList.cpp
        DataStruct/TextBook/3_Array.cpp
        DataStruct/TextBook/3_Array.hpp
        DataStruct/TextBook/4_Queue.cpp
        DataStruct/TextBook/4_Queue.hpp
        DataStruct/TextBook/4_Stack.cpp
        DataStruct/TextBook/4_Stack.hpp
        DataStruct/TextBook/7_Tree.cpp
        DataStruct/TextBook/7_Tree.hpp
        DataStruct/TextBook/8_Graph.cpp
        DataStruct/TextBook/8_Graph.hpp)
