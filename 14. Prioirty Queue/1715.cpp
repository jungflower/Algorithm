#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (n--) {
        int x;
        cin >> x;
        pq.push(x);
    }

    long long total = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long s = a + b;
        total += s;
        pq.push(s);
    }
    cout << total;
    return 0;
}