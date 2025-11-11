project(TodoListCLI)

set(CMAKE_CXX_STANDARD 17)

set(CPP_SOURCE
    main.cpp
    src/InteractionHandler.cpp
    src/TaskList.cpp
    )

add_executable(ToDoList ${CPP_SOURCE})