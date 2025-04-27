// 1182 부분수열의 합
// -> 다시 풀어보기
// 부분 수열의 합 = 2^n - 1 (-1은 공집합)
#include <iostream>
using namespace std;

int N, S;
int arr[25];
int sum, cnt;

void func(int cur, int sum){
    if(cur == N){
        if(sum == S)    ++cnt;
        return;
    }
    func(cur+1, sum); // 현재 원소 안쓰고 넘어가기
    func(cur+1, sum + arr[cur]); // 현재 원소를 선택해서 합에 추가가
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i=0; i < N; ++i)    cin >> arr[i];
    func(0, 0);
    if(S == 0)  cnt--; // 공집합 제외
    cout << cnt;
    return 0;
}