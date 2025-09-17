#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

// Push element into stack
void push(int x) {
    int sz = q.size();
    q.push(x);  // new element goes to back

    // Move previous elements behind new element
    for (int i = 0; i < sz; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Pop element from stack
void pop() {
    if (q.empty()) {
        cout << "Stack Underflow\n";
        return;
    }
    q.pop();
}

// Get top element
int top() {
    if (q.empty()) {
        cout << "Stack is Empty\n";
        return -1;  // return invalid value
    }
    return q.front();
}

// Check if stack is empty
bool empty() {
    return q.empty();
}

int main() {
    push(5);
    push(9);
    cout << top() << "\n";  // should print 9
    pop();
    cout << top() << "\n";  // should print 5
    return 0;
}
