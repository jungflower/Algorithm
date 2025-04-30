#include <iostream>
using namespace std;

int n, m;
int dp[100002];
int A[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> A[i];
    }

    // 구간합 구하기
    dp[1] = A[1];
    for(int i=2; i<=n; ++i){
        dp[i] = dp[i-1] + A[i];
    }

    while(m--){
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << '\n';
    }

    return 0;
}