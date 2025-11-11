#include "../include/TaskList.h"    


    void TaskList::printTasks(){
        std::cout << "To Do List: " << '\n';
        int i = 1;

        for(Task task: task_list){
                    std::cout << std::to_string(i) + "." << task.description << '\n';
                    i++;
            } 

    }
    

    void TaskList::addTask(const Task task){
        task_list.push_back(task);

    }
    

    void TaskList::removeTask(int task_number){
        task_list.erase(task_list.begin() + task_number + 1);
    }


    void TaskList::markComplete(int task_number){
       Task& task_to_complete = task_list[task_number - 1];
       task_to_complete.status = true;
       task_to_complete.description = task_to_complete.description + "  +[COMPLETE]+ ";

    }