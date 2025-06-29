#include <iostream>
#include <algorithm>
using namespace std;

int n;
int A[1002], dp[1002]; // i번째 수를 마지막으로 하는 증가 수열 중에서, 합이 가장 큰 값

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i)    cin >> A[i];

    for(int i=0; i < n; ++i){
        dp[i] = A[i]; // 자기 자신만 포함될 때
        for(int j = 0; j < i; ++j){
            if(A[i] > A[j]){
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }
    sort(dp, dp+n);
    cout << dp[n-1];
    return 0;
}