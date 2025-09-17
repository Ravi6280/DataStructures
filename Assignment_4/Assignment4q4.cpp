#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;

    queue<char> q;
    int freq[256] = {0};  // ASCII frequency array

    for (char c : s) {
        freq[c]++;       // update frequency
        q.push(c);       // push into queue

        // Remove repeating chars from the front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // Print result
        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }

    return 0;
}
