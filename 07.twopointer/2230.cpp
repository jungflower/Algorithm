// 이분 탐색
#if 0 
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int A[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)    cin >> A[i];
    sort(A, A + n);

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int target = m + A[i];
        int idx = lower_bound(A + i + 1, A + n, target) - A;

        if (idx < n) {
            ans = min(ans, A[idx] - A[i]);
        }
    }
    cout << ans;

    return 0;
}
#endif

// 투 포인터
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)    cin >> A[i];
    sort(A, A + n);

    // 내가 푼거
    /*
    int st = 0, en = 1, ans = 0x7fffffff;
    while(st < n && en < n){
        if(A[en] - A[st] >= m){
            ans = min(ans, A[en] - A[st]);
            st++;
        }
        else{
            en++;
        }
    }
    */
    int en = 0, ans = 0x7fffffff;
    for (int st = 0; st < n; ++st) {
        while (en < n && A[en] - A[st] < m)  en++;
        if (en == n) break;
        ans = min(ans, A[en] - A[st]);
    }

    cout << ans;

    return 0;
}