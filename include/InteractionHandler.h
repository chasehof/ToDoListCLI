#pragma once

#include <variant>
#include <iostream>
#include <memory>
#include "TaskList.h"

enum class Choice
{
    Add,
    Remove,
    Complete
};


class InteractionHandler
{
    public:

        InteractionHandler(std::shared_ptr<TaskList> task): t(task) {}

        /**
        * @brief prompts the user to add, remove, or mark a task as complete also gives user choice to quit the program
        * @param none 
        * @return returns a strongly typed value that will be the input for future prompts 
        **/
        void handleInput();

        /**
        * @brief Uses users choice to actually add remove or mark complete a certain task
        * @param none 
        * @return none
        **/
        void parseInput(const Choice choice);

        private:
        
        std::shared_ptr<TaskList> t;



};