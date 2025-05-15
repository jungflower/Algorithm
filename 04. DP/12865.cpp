// 12865 평범한 배낭 
#include <iostream>
using namespace std;

int n, k;
int w[102], v[102];
int dp[102][100002]; // i번째의 물건을 판단했을 때, j 만큼의 무게 할당량까지의 최대의 가치

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=1; i <= n; ++i)
        cin >> w[i] >> v[i];
    
    for(int i=1; i <= n; ++i){
        for(int j=0; j <= k; ++j){
            // i번째 물건 포함 X
            dp[i][j] = dp[i-1][j];

            // i번째 물건 포함
            if(j >= w[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
                //cout << i << ' ' << j << ' ' << dp[i][j] << '\n'; 
            }   
        }
    }

    cout << dp[n][k];

    return 0;
}