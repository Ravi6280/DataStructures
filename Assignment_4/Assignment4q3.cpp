#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    int half = n / 2;
    queue<int> firstHalf;

    // Move first half to another queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Interleave elements from both halves
    while (!firstHalf.empty() && !q.empty()) {
        cout << firstHalf.front() << " ";
        firstHalf.pop();
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
