#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

struct Task
{
    std::string description{};
    bool status{0};
};


class TaskList
{
    public:
    
    /**
     * @brief prints a list of the current tasks 
     * @param none 
     * @return none 
    **/
    void printTasks();
    
    /**
     * @brief adds a task to the task list 
     * @param task includes the description taken in by the Interaction Handler
     * @return none 
    **/
    void addTask(const Task task);
    
    /**
     * @brief Removes a task from the task_list
     * @param task_number the index of the task to remove from the list 
     * @return none 
    **/
    void removeTask(int task_number);


    /**
     * @brief Removes a task from the task_list
     * @param task_number the index of the task to mark complete from the list
     * @return none 
    **/
    void markComplete(int task_number);

    private:

    std::vector<Task> task_list{};
};