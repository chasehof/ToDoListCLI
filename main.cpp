#include <iostream>
#include <memory>
#include "include/TaskList.h"
#include "include/InteractionHandler.h"


int main(){
    auto listhandler = std::make_shared<TaskList>();
    InteractionHandler interactionhandler(listhandler);

    while(1){
        listhandler->printTasks();
        interactionhandler.handleInput();
    }

    return 0;
}