#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

// Push element into stack
void push(int x) {
    // Always push into q2 first
    q2.push(x);

    // Move all elements from q1 to q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    // Swap q1 and q2
    swap(q1, q2);
}

// Pop element from stack
void pop() {
    if (q1.empty()) {
        cout << "Stack Underflow\n";
        return;
    }
    q1.pop();
}

// Get top element of stack
int top() {
    if (q1.empty()) {
        cout << "Stack is Empty\n";
        return -1; // return an invalid value
    }
    return q1.front();
}

// Check if stack is empty
bool empty() {
    return q1.empty();
}

int main() {
    push(10);
    push(20);
    cout << top() << "\n";  // should print 20
    pop();
    cout << top() << "\n";  // should print 10
    return 0;
}

