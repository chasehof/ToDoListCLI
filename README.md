# ToDo List CLI

A feature-rich command-line to-do list application for managing tasks directly from your terminal.

## Prerequisites

- CMake 3.10 or higher
- C++ compiler with C++17 support (GCC, Clang, or MSVC)
- Make or Ninja build system

## Building

### Clone the repository

```bash
git clone https://github.com/chasehof/ToDoListCLI.git
cd ToDoListCLI
```

### Build with CMake

```bash
mkdir build
cd build
cmake ..
make
```

The executable will be created as `ToDoList` in the `build` directory.

## Running

```bash
./build/ToDoList
```

### Using the Application

1. **Add a Task** - Select option 1, enter a description, choose priority (optional), and add a due date (optional)
2. **Remove a Task** - Select option 2 and enter the task number
3. **Mark Complete** - Select option 3 and enter the task number
4. **Exit** - Select option 4 to quit (tasks are automatically saved)

### Example Session

```
Welcome to ToDoList CLI!

=== TO DO LIST (Empty) ===

=== MENU ===
1. Add a task
2. Remove a task
3. Mark task as complete
4. Exit
Select an option (1-4): 1
Enter task description: Buy groceries
Enter priority (Low/Medium/High) [default: Medium]: High
Enter due date (optional, e.g., 2025-12-31): 2025-12-31
Task added successfully!

=== TO DO LIST ===
----------------------------------------------------------------------
1. [ ] Buy groceries (Due: 2025-12-31) [High]
----------------------------------------------------------------------
```

## Data Storage

Tasks are automatically saved to a `tasks.dat` file in the directory where you run the application. This file is created when you exit the program and automatically loaded when you start it again.


## License

MIT License
