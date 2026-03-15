#include <iostream>
#include <memory>
#include "include/TaskList.h"
#include "include/InteractionHandler.h"


int main() {
    auto listhandler = std::make_shared<TaskList>();
    InteractionHandler interactionhandler(listhandler);

    std::cout << "Welcome to ToDoList CLI!" << std::endl;

    while (true) {
        listhandler->printTasks();
        if (!interactionhandler.handleInput()) {
            break;
        }
    }

    return 0;
}