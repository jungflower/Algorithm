// 16401 과자 나눠주기
#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int snack[1000002];

bool solve(int target) {
    long long cur = 0;
    for (int i = 0; i < n; ++i)    cur += snack[i] / target;
    return cur >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> snack[i];
    }

    sort(snack, snack + n);
    long long st = 1;
    long long en = 1000000000;
    en = max(en, (long long)snack[n - 1]);

    while (st < en) {
        int mid = (st + en + 1) / 2;
        if (solve(mid))  st = mid;
        else    en = mid - 1;
        //cout << "st: " << st << "en: " << en << '\n';
    }

    // int cnt = 0;
    // for (int i = 0; i < n; ++i) {
    //     cnt += snack[i] / st;
    // }
    cout << ((solve(st)) ? st : 0) << '\n';

    return 0;
}