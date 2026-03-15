#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

enum class Priority
{
    Low,
    Medium,
    High
};

struct Task
{
    std::string description{};
    bool status{false};
    Priority priority{Priority::Medium};
    std::string dueDate{};
};


class TaskList
{
    public:
    
    TaskList();
    ~TaskList();
    
    /**
     * @brief prints a list of the current tasks with formatting
     * @param none 
     * @return none 
    **/
    void printTasks() const;
    
    /**
     * @brief adds a task to the task list 
     * @param task includes the description taken in by the Interaction Handler
     * @return true if task was added successfully
    **/
    bool addTask(const Task& task);
    
    /**
     * @brief Removes a task from the task_list
     * @param task_number the index of the task to remove from the list 
     * @return true if task was removed successfully
    **/
    bool removeTask(int task_number);

    /**
     * @brief Marks a task as complete
     * @param task_number the index of the task to mark complete from the list
     * @return true if task was marked successfully
    **/
    bool markComplete(int task_number);

    /**
     * @brief Gets the size of the task list
     * @return number of tasks in the list
    **/
    size_t getTaskCount() const { return task_list.size(); }

    /**
     * @brief Saves tasks to a file
     * @return true if save was successful
    **/
    bool saveTasks() const;

    /**
     * @brief Loads tasks from a file
     * @return true if load was successful
    **/
    bool loadTasks();

    /**
     * @brief Clears all tasks
     * @return none
    **/
    void clearAll();

    private:

    std::vector<Task> task_list{};
    const std::string SAVE_FILE = "tasks.dat";
    
    std::string priorityToString(Priority p) const;
    Priority stringToPriority(const std::string& s) const;
};