#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to set precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    stack<char> operators;
    string postfix;

    for (char token : infix) {
        if (isalnum(token)) {
            postfix += token;   // operand → directly add to output
        }
        else if (token == '(') {
            operators.push(token);
        }
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // pop '('
        }
        else { // operator
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    // pop any remaining operators
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    cout << "Postfix Expression: " << postfix << "\n";
    return 0;
}
