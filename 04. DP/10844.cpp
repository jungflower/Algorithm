#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    
    while(t--){
        int n;
        cin >> n;

        long long dp[102];
        dp[1] = 1; dp[2] = 1; dp[3] = 1;
        for(int i=4; i <= n; ++i){
            dp[i] = dp[i-3] + dp[i-2];
        }
        cout << dp[n] << '\n';
    }


    return 0;
}