#include <iostream>
#include <algorithm>
using namespace std;

// 2차원 배열로 
#if 0
int n;
int step[302];
int dp[302][302];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i <= n; ++i){
        cin >> step[i];
    }
    // 초기값 설정
    dp[1][1] = step[1];
    dp[1][2] = 0;
    dp[2][1] = step[2];
    dp[2][2] = step[1] + step[2];

    for(int i=3; i <= n; ++i){
        // i번째 계단에 왔을 때, 1칸 건너뛰고 왔을 때 = 즉, i-2번째 계단에서 올라옴
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + step[i];
        // i번째 계단에 왔을 때, 직전 계단에서 왔을 때
        dp[i][2] = dp[i-1][1] + step[i];
    }

    cout << max(dp[n][1], dp[n][2]);
    return 0;
}
#endif

int s[300];
int n;
int dp[300];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int tot=0;
    for(int i=1; i <= n; ++i){
        cin >> s[i];
        tot += s[i];
    }
    if(n <= 2){
        cout << tot;
        return 0;
    }
    dp[1] = s[1];    dp[2] = s[2];    dp[3] = s[3];
    for(int i=4; i <= n-1; ++i){
        dp[i] = min(dp[i-2], dp[i-3]) + s[i];
    }
    cout << tot - min(dp[n-1], dp[n-2]);
    return 0;
}
