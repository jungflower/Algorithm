#include <iostream>
#include <algorithm>
using namespace std;

int t;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n] = { 0, };
        int b[m] = { 0, };
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        sort(a, a + n);   sort(b, b + m);

        int pair_cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i] > b[j]) pair_cnt++;
                else    break;
            }
        }
        cout << pair_cnt << '\n';
    }

    return 0;
}