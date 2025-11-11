#include "../include/InteractionHandler.h"  
#include <limits>


void InteractionHandler::handleInput(){
    char input{};
   
        std::cout << "Enter one of the following \n A to add a task to the list \n R to remove a task from the list \n C to mark a task as complete \n Q to quit: ";
        std::cin >> input;

        switch(input){

            case 'A': 
                parseInput(Choice::Add);
                break;
            case 'R':
                parseInput(Choice::Remove);
                break;
            case 'C':
                parseInput(Choice::Complete);
                break;
            case 'Q':
                return;
            default:
                std::cout << "invalid input entered!" << '\n';
                return;
            }
    }


    
void InteractionHandler::parseInput(const Choice choice){
    switch(choice){
        case Choice::Add:
        {
            std::string description{};
            Task task_to_add; 
            std::cout << "Enter a Description for the task to add: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, description);
            task_to_add.description = description;
            t->addTask(task_to_add);
            break;
        }
        case Choice::Remove:
        {
            int index{};
            std::cout << "Enter the index for the task to remove: ";
            std::cin >> index;
            t->removeTask(index);
            break;
        }
        case Choice::Complete:
        {
            int index{};
            std::cout << "Enter the index for the task to mark as complete: ";
            std::cin >> index;
            t->markComplete(index);
            break;
        }
        default:
            return;
    }
}
