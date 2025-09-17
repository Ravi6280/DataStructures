#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(const string& expr) {
    stack<char> brackets;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty()) return false;

            char topChar = brackets.top();
            brackets.pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main() {
    string input;
    cout << "Enter expression: ";
    cin >> input;

    if (isBalanced(input))
        cout << "✅ Expression is Balanced\n";
    else
        cout << "❌ Expression is Not Balanced\n";

    return 0;
}
