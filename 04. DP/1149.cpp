#include <iostream>
#include <algorithm>
using namespace std;

int n;
int house[1002][3];
int dp[1002][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i <= n; ++i){
        for(int j=0; j < 3; ++j){
            cin >> house[i][j];
            
        }
    }
    // 초기값
    dp[1][0] = house[1][0]; dp[1][1] = house[1][1]; dp[1][2] = house[1][2];

    for(int i=2; i <= n; ++i){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }
    
    cout << min({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}