#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Recursive function to create linked list
Node* createList(int n) {
    if (n <= 0) {
        return nullptr; // Base case: no nodes to create
    }

    int value;
    cout << "Enter value for node: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;

    // Recursively create the rest of the list
    newNode->next = createList(n - 1);

    return newNode;
}

// Recursive function to display linked list
void displayList(Node* head) {
    if (head == nullptr) {
        return; // Base case: end of list
    }
    cout << head->data << " -> ";
    displayList(head->next);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = createList(n);

    cout << "\nLinked List: ";
    displayList(head);
    cout << "NULL\n";

    return 0;
}
