#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<string> todoList;
    int choice;
    string task;

    do {
        cout << "\n===== To-Do List Menu =====\n";
        cout << "1. Add task at front\n";
        cout << "2. Add task at back\n";
        cout << "3. Remove completed task\n";
        cout << "4. Search a task\n";
        cout << "5. Reverse list\n";
        cout << "6. Display tasks\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To remove leftover newline

        switch(choice) {
            case 1:
                cout << "Enter task to add at front: ";
                getline(cin, task);
                todoList.push_front(task);
                break;

            case 2:
                cout << "Enter task to add at back: ";
                getline(cin, task);
                todoList.push_back(task);
                break;

            case 3: {
                cout << "Enter completed task to remove: ";
                getline(cin, task);

                auto it = find(todoList.begin(), todoList.end(), task);
                if (it != todoList.end()) {
                    todoList.erase(it);
                    cout << "Task removed successfully!\n";
                } else {
                    cout << "Task not found!\n";
                }
                break;
            }

            case 4: {
                cout << "Enter task to search: ";
                getline(cin, task);

                auto it = find(todoList.begin(), todoList.end(), task);
                if (it != todoList.end()) {
                    cout << "Task found: " << *it << endl;
                } else {
                    cout << "Task not found!\n";
                }
                break;
            }

            case 5:
                todoList.reverse();
                cout << "List reversed successfully!\n";
                break;

            case 6:
                cout << "\nCurrent To-Do List:\n";
                for (auto &t : todoList) {
                    cout << "- " << t << endl;
                }
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
