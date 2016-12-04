cmake_minimum_required(VERSION 2.8)
project(random)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} cellular_automata)

add_dependencies(${PROJECT_NAME} cellular_automata)
