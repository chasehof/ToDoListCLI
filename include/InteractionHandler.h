#pragma once

#include <variant>
#include <iostream>
#include <memory>
#include "TaskList.h"

enum class Choice
{
    Add,
    Remove,
    Complete,
    Exit
};


class InteractionHandler
{
    public:

        InteractionHandler(std::shared_ptr<TaskList> task): t(task) {}

        /**
        * @brief prompts the user to add, remove, or mark a task as complete
        * @param none 
        * @return true if user wants to continue, false if user wants to quit
        **/
        bool handleInput();

        /**
        * @brief Uses users choice to actually add remove or mark complete a certain task
        * @param choice the user's choice
        * @return none
        **/
        void parseInput(const Choice choice);

        private:
        
        std::shared_ptr<TaskList> t;
        
        void displayMenu() const;
        int getValidatedInput(int min, int max) const;
};