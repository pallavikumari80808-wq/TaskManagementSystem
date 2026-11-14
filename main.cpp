
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Structure to store task details
struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

// Function to add a new task
void addTask() {
    Task t;

    cout << "Enter task name: ";
    getline(cin, t.name);

    if (t.name.empty()) {
        cout << "Task name cannot be empty!\n";
        return;
    }

    t.completed = false;
    tasks.push_back(t);

    cout << "Task added successfully!\n";
}

// Function to display all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n===== YOUR TASKS =====\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name;

        if (tasks[i].completed)
            cout << " [Completed]\n";
        else
            cout << " [Pending]\n";
    }
}

// Function to mark a task completed
void completeTask() {
    int number;

    viewTasks();

    if (tasks.empty()) return;

    cout << "Enter task number: ";

    if (!(cin >> number)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (number >= 1 && number <= tasks.size()) {
        tasks[number - 1].completed = true;
        cout << "Task completed successfully!\n";
    }
    else {
        cout << "Invalid task number!\n";
    }
}

// Function to delete a task
void deleteTask() {
    int number;

    viewTasks();

    if (tasks.empty()) return;

    cout << "Enter task number to delete: ";

    if (!(cin >> number)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (number >= 1 && number <= tasks.size()) {
        tasks.erase(tasks.begin() + number - 1);
        cout << "Task deleted successfully!\n";
    }
    else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n================================\n";
        cout << "       TASK MANAGEMENT SYSTEM\n";
        cout << "================================\n";

        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                completeTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                cout << "Thank you for using Task Manager!\n";
                return 0;

            default:
                cout << "Invalid choice! Please select 1-5.\n";
        }
    }

    return 0;
}
