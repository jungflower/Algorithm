// 12865 평범한 배낭
// xxx 못풀어서 다시 풀기 ..
#include <iostream>
using namespace std;

int n, k;
int dp[102][100002]; // i개의 물건 수까지 고려했을 때, 남은 무게가 j일 때의 최대 가치
struct Info{int w; int v;}; 
Info stuff[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=1; i <= n; ++i){
        cin >> stuff[i].w >> stuff[i].v;
    }

    for(int i=1; i <= n; ++i){
        for(int j=0; j <= k; ++j){
            // i번째 물건 포함 안하는 경우
            dp[i][j] = dp[i-1][j];

            // i번째 물건 포함하는 경우 (현재 배낭의 용량이 물건 i의 무게보다 크거나 같을 때)
            if(j >= stuff[i].w){
                dp[i][j] = max(dp[i][j], dp[i-1][j - stuff[i].w] + stuff[i].v);
            }
        }   
    }   
    cout << dp[n][k] << '\n';
    return 0;
}