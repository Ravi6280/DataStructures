#include <iostream>
using namespace std;

const int SIZE = 100;
int cq[SIZE];
int front = -1, rear = -1;

// Check if queue is empty
bool isEmpty() {
    return (front == -1);
}

// Check if queue is full
bool isFull() {
    return ((rear + 1) % SIZE == front);
}

// Insert element
void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }
    if (isEmpty()) front = 0; // first element
    rear = (rear + 1) % SIZE;
    cq[rear] = x;
}

// Remove element
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Dequeued " << cq[front] << "\n";
    if (front == rear) {
        front = rear = -1; // reset
    } else {
        front = (front + 1) % SIZE;
    }
}

// Peek front element
void peek() {
    if (isEmpty()) cout << "Empty\n";
    else cout << "Front: " << cq[front] << "\n";
}

// Display queue
void display() {
    if (isEmpty()) {
        cout << "Empty\n";
        return;
    }
    int i = front;
    while (true) {
        cout << cq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << "\n";
}

int main() {
    int choice, x;
    cout << "1.Enqueue  2.Dequeue  3.IsEmpty  4.IsFull  5.Display  6.Peek  0.Exit\n";
    do {
        cin >> choice;
        switch (choice) {
            case 1: cin >> x; enqueue(x); break;
            case 2: dequeue(); break;
            case 3: cout << (isEmpty() ? "Yes\n" : "No\n"); break;
            case 4: cout << (isFull() ? "Yes\n" : "No\n"); break;
            case 5: display(); break;
            case 6: peek(); break;
        }
    } while (choice != 0);

    return 0;
}
