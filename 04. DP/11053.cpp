#include <iostream>
using namespace std;

int n;
int A[1002], dp[1002]; // i번쨰 값이 가지는 가장 긴 증가하는 부분 수열의 길이 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)    cin >> A[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}