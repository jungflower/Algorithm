// 10844 쉬운 계단 수 
#include <iostream>
using namespace std;

long long dp[102][102]; // 길이가 i고, 마지막 숫자가 j인 계단 수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    // 초기 값
    for(int i = 1; i <= 9; ++i){ 
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= 9; ++j){
            if(j >= 1){
                dp[i][j] += dp[i-1][j-1];
            }
            if(j <= 8){
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= 1000000000;
        }
    }

    // for(int i=0; i <= 9; ++i){
    //     cout << i << ' ' << dp[n][i] << '\n';
    // }

    long long sum = 0;
    for(int i=0; i <= 9; ++i){
        sum = (sum + dp[n][i]) % 1000000000;
    }
    cout << sum;

    return 0;
}