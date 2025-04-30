#include <iostream>
using namespace std;

int n;
int dp[1000002], pre[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp[1] = 0;
    pre[1] = 0;

    for(int i = 2; i <= n; ++i){
        dp[i] = dp[i-1] + 1;
        pre[i] = i-1;

        if(i % 3 == 0 && dp[i/3] + 1 < dp[i]){
            dp[i] = dp[i/3] + 1;
            pre[i] = i/3;
        }
        if(i % 2 == 0 && dp[i/2] + 1 < dp[i]){
            dp[i] = dp[i/2] + 1;
            pre[i] = i/2;
        }
    }

    cout << dp[n] << '\n';
    
    int cur = n;
    while(1){
        cout << cur << ' ';
        if(cur == 1)    break;
        cur = pre[cur];
    }

    return 0;
}