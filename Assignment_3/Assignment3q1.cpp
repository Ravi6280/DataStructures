#include <iostream>
using namespace std;

#define SIZE 100   // renamed from MAX

int stackData[SIZE];  
int topIndex = -1;   // renamed from top

bool emptyStack() { return topIndex == -1; }
bool fullStack()  { return topIndex == SIZE - 1; }

void pushItem(int element) {
    if (fullStack())
        cout << "⚠️ Stack Overflow!\n";
    else
        stackData[++topIndex] = element;
}

void popItem() {
    if (emptyStack())
        cout << "⚠️ Stack Underflow!\n";
    else
        cout << "Removed: " << stackData[topIndex--] << "\n";
}

void showTop() {
    if (emptyStack())
        cout << "Stack is Empty!\n";
    else
        cout << "Top Element → " << stackData[topIndex] << "\n";
}

void printStack() {
    if (emptyStack()) {
        cout << "Stack is Empty!\n";
        return;
    }
    cout << "Stack Elements (Top → Bottom): ";
    for (int i = topIndex; i >= 0; i--) {
        cout << stackData[i] << " ";
    }
    cout << "\n";
}

int main() {
    int option, item;
    do {
        cout << "\n===== Stack Operations Menu =====\n";
        cout << "1. Push\n2. Pop\n3. Is Empty?\n4. Is Full?\n";
        cout << "5. Print Stack\n6. Show Top\n0. Exit\n";
        cout << "Enter option: ";
        if (!(cin >> option)) break;

        switch (option) {
            case 1:
                cout << "Enter value to push: ";
                cin >> item;
                pushItem(item);
                break;
            case 2: popItem(); break;
            case 3: cout << (emptyStack() ? "Yes, Stack is Empty\n" : "No, Stack has elements\n"); break;
            case 4: cout << (fullStack() ? "Yes, Stack is Full\n" : "No, Stack has space\n"); break;
            case 5: printStack(); break;
            case 6: showTop(); break;
            case 0: cout << "Exiting Program...\n"; break;
            default: cout << "❌ Invalid option! Try again.\n";
        }
    } while (option != 0);

    return 0;
}
