#include <iostream>
using namespace std;

int n, k;
int arr[1000002];

bool solve(int target) {
    long long cur = 0;
    for (int i = 0; i < k; ++i)    cur += arr[i] / target;
    return cur >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; ++i)    cin >> arr[i];

    long long st = 1;
    long long en = 0x7fffffff; // 2^32 - 1
    while (st < en) {
        long long mid = (st + en + 1) / 2;
        if (solve(mid)) st = mid;
        else     en = mid - 1;
    }
    cout << st;

    return 0;
}