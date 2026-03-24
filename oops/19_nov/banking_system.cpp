#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> bankQueue;
    int choice;
    string name;

    do {
        cout << "\n===== Bank Queue System =====\n";
        cout << "1. Add customer to queue\n";
        cout << "2. Serve customer\n";
        cout << "3. Show next customer\n";
        cout << "4. Display all customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline character

        switch(choice) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, name);
                bankQueue.push_back(name);
                cout << "Customer added to queue.\n";
                break;

            case 2:
                if (!bankQueue.empty()) {
                    cout << "Serving customer: " << bankQueue.front() << endl;
                    bankQueue.pop_front();
                } else {
                    cout << "Queue is empty! No customers to serve.\n";
                }
                break;

            case 3:
                if (!bankQueue.empty()) {
                    cout << "Next customer: " << bankQueue.front() << endl;
                } else {
                    cout << "Queue is empty!\n";
                }
                break;

            case 4:
                if (bankQueue.empty()) {
                    cout << "Queue is empty!\n";
                } else {
                    cout << "Current customers in queue:\n";
                    for (auto &customer : bankQueue) {
                        cout << "- " << customer << endl;
                    }
                }
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
