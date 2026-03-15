cmake_minimum_required(VERSION 3.10)
project(TodoListCLI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPP_SOURCE
    main.cpp
    src/InteractionHandler.cpp
    src/TaskList.cpp
    )

add_executable(ToDoList ${CPP_SOURCE})
target_include_directories(ToDoList PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})