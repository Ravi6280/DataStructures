#include <iostream>
#include <stack>
using namespace std;

int main() {
    string input;
    cin >> input;

    stack<char> charStack;

    // push characters one by one
    for (auto ch : input) {
        charStack.push(ch);
    }

    cout << "Reversed string: ";
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    cout << "\n";

    return 0;
}
