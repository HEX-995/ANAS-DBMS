#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Account {
private:
    int pin;
    double balance;
    vector<string> transactions;

public:
    Account(int p, double b) {
        pin = p;
        balance = b;
    }

    bool verifyPin(int enteredPin) {
        return enteredPin == pin;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back("Deposited: " + to_string(amount));
        cout << "Amount deposited successfully\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance\n";
            return;
        }
        balance -= amount;
        transactions.push_back("Withdrawn: " + to_string(amount));
        cout << "Amount withdrawn successfully\n";
    }

    void balanceEnquiry() {
        cout << "Current Balance: " << balance << endl;
    }

    void showTransactions() {
        if (transactions.empty()) {
            cout << "No transactions available\n";
            return;
        }
        cout << "Last Transactions:\n";
        int start = max(0, (int)transactions.size() - 5);
        for (int i = start; i < transactions.size(); i++) {
            cout << transactions[i] << endl;
        }
    }
};

int main() {
    Account acc(1234, 5000);
    int pin, choice;

    cout << "Enter PIN: ";
    cin >> pin;

    if (!acc.verifyPin(pin)) {
        cout << "Invalid PIN\n";
        return 0;
    }

    cout << "\n1. Deposit\n2. Withdraw\n3. Balance Enquiry\n4. View Transactions\n5. Exit\n";
    do {
    cout << "Enter choice: ";
    cin >> choice;

        if (choice == 1) {
            double amt;
            cout << "Enter amount: ";
            cin >> amt;
            acc.deposit(amt);
        }
        else if (choice == 2) {
            double amt;
            cout << "Enter amount: ";
            cin >> amt;
            acc.withdraw(amt);
        }
        else if (choice == 3) {
            acc.balanceEnquiry();
        }
        else if (choice == 4) {
            acc.showTransactions();
        }


    } while (choice !=5);

    cout << "Thank you for using banking services\n";
    return 0;
}
