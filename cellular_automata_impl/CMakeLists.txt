cmake_minimum_required(VERSION 2.8)
project(cellular_automata)

add_library(${PROJECT_NAME} SHARED
    cellular_automata_impl.h
    cellular_automata_impl.cpp
)
