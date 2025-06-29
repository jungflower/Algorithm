// 12865 평범한 배낭
// xxx 못풀어서 다시 풀기 ..
/*
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
*/

// 2차원 배열로 구현
#if 0
#include <iostream>
#include <vector>
using namespace std;

int n, k;
struct info { int w, v; };
vector<info> stuff;
int dp[102][100002]; // i번째 물건까지 확인했을 때, 배낭 무게가 j일때의 최대 가치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    stuff.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> stuff[i].w >> stuff[i].v;
    }


    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j]; // i번째 물건 포함하지 않을 때
            if (j >= stuff[i].w) { // i번째 물건이 포함될 때 (j만큼의 무게보다 작은 경우 포함)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stuff[i].w] + stuff[i].v);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}
#endif

// 1차원 배열로 구현
#include <iostream>
#include <vector>
using namespace std;

int n, k;
struct info {int w, v;};
vector<info> stuff;
int dp[1000002]; // 배낭무게가 j일 때의 최대 가치

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    stuff.resize(n+1);
    for(int i=1; i <= n; ++i)    cin >> stuff[i].w >> stuff[i].v;

    for(int i=1; i <= n; ++i){
        for(int j = k; j >= stuff[i].w; --j){ // 중복 방지로 역순으로 탐색
            dp[j] = max(dp[j], dp[j - stuff[i].w] + stuff[i].v);
        }
    }
    cout << dp[k] << '\n';

    return 0;
}