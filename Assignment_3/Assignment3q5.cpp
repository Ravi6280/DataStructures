#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    stack<int> values;

    for (char token : postfix) {
        if (isdigit(token)) {
            values.push(token - '0');  // convert char digit → int
        } else {
            int right = values.top(); values.pop();
            int left  = values.top(); values.pop();

            switch (token) {
                case '+': values.push(left + right); break;
                case '-': values.push(left - right); break;
                case '*': values.push(left * right); break;
                case '/': values.push(left / right); break;
            }
        }
    }

    cout << "Result = " << values.top() << "\n";
    return 0;
}
