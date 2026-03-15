#include "../include/InteractionHandler.h"  
#include <limits>
#include <cctype>


void InteractionHandler::displayMenu() const {
    std::cout << "\n=== MENU ===\n"
              << "1. Add a task\n"
              << "2. Remove a task\n"
              << "3. Mark task as complete\n"
              << "4. Exit\n"
              << "Select an option (1-4): ";
}

int InteractionHandler::getValidatedInput(int min, int max) const {
    int input;
    while (!(std::cin >> input) || input < min || input > max) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number between " 
                  << min << " and " << max << ": ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

bool InteractionHandler::handleInput() {
    displayMenu();
    int input = getValidatedInput(1, 4);

    switch (input) {
        case 1: 
            parseInput(Choice::Add);
            return true;
        case 2:
            parseInput(Choice::Remove);
            return true;
        case 3:
            parseInput(Choice::Complete);
            return true;
        case 4:
            parseInput(Choice::Exit);
            return false;
        default:
            return true;
    }
}

void InteractionHandler::parseInput(const Choice choice) {
    switch (choice) {
        case Choice::Add: {
            std::string description{};
            std::string priority_input{};
            std::string due_date{};
            
            Task task_to_add;
            
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            task_to_add.description = description;
            
            std::cout << "Enter priority (Low/Medium/High) [default: Medium]: ";
            std::getline(std::cin, priority_input);
            
            if (!priority_input.empty()) {
                if (priority_input == "Low" || priority_input == "low") {
                    task_to_add.priority = Priority::Low;
                } else if (priority_input == "High" || priority_input == "high") {
                    task_to_add.priority = Priority::High;
                }
            }
            
            std::cout << "Enter due date (optional, e.g., 2025-12-31): ";
            std::getline(std::cin, due_date);
            if (!due_date.empty()) {
                task_to_add.dueDate = due_date;
            }
            
            t->addTask(task_to_add);
            break;
        }
        
        case Choice::Remove: {
            if (t->getTaskCount() == 0) {
                std::cout << "Error: No tasks to remove!" << std::endl;
                return;
            }
            
            std::cout << "Enter the task number to remove: ";
            int index = getValidatedInput(1, static_cast<int>(t->getTaskCount()));
            t->removeTask(index);
            break;
        }
        
        case Choice::Complete: {
            if (t->getTaskCount() == 0) {
                std::cout << "Error: No tasks to mark complete!" << std::endl;
                return;
            }
            
            std::cout << "Enter the task number to mark as complete: ";
            int index = getValidatedInput(1, static_cast<int>(t->getTaskCount()));
            t->markComplete(index);
            break;
        }
        
        case Choice::Exit: {
            std::cout << "Goodbye!" << std::endl;
            return;
        }
        
        default:
            return;
    }
}
