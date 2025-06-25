#include <iostream>
using namespace std;

int dp[16];
int n;
int T[16], P[16];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> P[i];
    }

    for (int i = 0; i < n; ++i) {
        if (i + T[i] <= n) { // 퇴사 전에 상담 끝난다면
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]); // 상담안하고 그냥 넘겼을 때때
    }
    cout << dp[n] << '\n';
    return 0;
}