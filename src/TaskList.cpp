#include "../include/TaskList.h"

TaskList::TaskList() {
    loadTasks();
}

TaskList::~TaskList() {
    saveTasks();
}

void TaskList::printTasks() const {
    if (task_list.empty()) {
        std::cout << "\n=== TO DO LIST (Empty) ===\n" << std::endl;
        return;
    }

    std::cout << "\n=== TO DO LIST ===\n";
    std::cout << std::string(70, '-') << '\n';
    
    int i = 1;
    for (const Task& task : task_list) {
        std::string status_str = task.status ? "[✓]" : "[ ]";
        std::string priority_str = priorityToString(task.priority);
        
        std::cout << i << ". " << status_str << " " << task.description;
        
        if (!task.dueDate.empty()) {
            std::cout << " (Due: " << task.dueDate << ")";
        }
        
        std::cout << " [" << priority_str << "]" << '\n';
        i++;
    }
    
    std::cout << std::string(70, '-') << '\n' << std::endl;
}

bool TaskList::addTask(const Task& task) {
    if (task.description.empty()) {
        std::cout << "Error: Task description cannot be empty!" << std::endl;
        return false;
    }
    
    task_list.push_back(task);
    std::cout << "Task added successfully!" << std::endl;
    return true;
}

bool TaskList::removeTask(int task_number) {
    if (task_number < 1 || task_number > static_cast<int>(task_list.size())) {
        std::cout << "Error: Invalid task number!" << std::endl;
        return false;
    }
    
    task_list.erase(task_list.begin() + task_number - 1);
    std::cout << "Task removed successfully!" << std::endl;
    return true;
}

bool TaskList::markComplete(int task_number) {
    if (task_number < 1 || task_number > static_cast<int>(task_list.size())) {
        std::cout << "Error: Invalid task number!" << std::endl;
        return false;
    }
    
    Task& task_to_complete = task_list[task_number - 1];
    
    if (task_to_complete.status) {
        std::cout << "Task is already marked as complete!" << std::endl;
        return false;
    }
    
    task_to_complete.status = true;
    std::cout << "Task marked as complete!" << std::endl;
    return true;
}

bool TaskList::saveTasks() const {
    std::ofstream file(SAVE_FILE);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open save file!" << std::endl;
        return false;
    }
    
    for (const Task& task : task_list) {
        file << task.description << "|"
             << task.status << "|"
             << priorityToString(task.priority) << "|"
             << task.dueDate << "\n";
    }
    
    file.close();
    return true;
}

bool TaskList::loadTasks() {
    std::ifstream file(SAVE_FILE);
    
    if (!file.is_open()) {
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        std::string description, status_str, priority_str, dueDate;
        
        if (std::getline(iss, description, '|') &&
            std::getline(iss, status_str, '|') &&
            std::getline(iss, priority_str, '|') &&
            std::getline(iss, dueDate, '|')) {
            
            Task task;
            task.description = description;
            task.status = (status_str == "1");
            task.priority = stringToPriority(priority_str);
            task.dueDate = dueDate;
            
            task_list.push_back(task);
        }
    }
    
    file.close();
    return true;
}

void TaskList::clearAll() {
    task_list.clear();
    saveTasks();
}

std::string TaskList::priorityToString(Priority p) const {
    switch (p) {
        case Priority::Low: return "Low";
        case Priority::Medium: return "Medium";
        case Priority::High: return "High";
        default: return "Unknown";
    }
}

Priority TaskList::stringToPriority(const std::string& s) const {
    if (s == "Low") return Priority::Low;
    if (s == "High") return Priority::High;
    return Priority::Medium;
}