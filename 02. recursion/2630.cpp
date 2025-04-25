// 2630 색종이 만들기 
#include <iostream>
using namespace std;

int N;
int paper[128][128];
int cnt[2] = {0, }; // 0 -> 하얀색, 1 -> 파란색

// n X n 내에서 (y, x)부터 같은지 판단하는 함수
bool check(int y, int x, int n){
    for(int i=y; i < y+n; ++i){
        for(int j=x; j < x+n; ++j){
            if(paper[i][j] != paper[y][x])  return false;
        }
    }
    return true;
}

void solve(int y, int x, int n){
    if(check(y, x, n)){
        ++cnt[paper[y][x]];
        return ;
    }

    solve(y, x, n/2);
    solve(y, x+n/2, n/2);
    solve(y+n/2, x, n/2);
    solve(y+n/2, x+n/2, n/2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i < N; ++i){
        for(int j=0; j < N; ++j){
            cin >> paper[i][j];
        }
    }
    solve(0, 0, N);
    for(int i=0; i < 2; ++i)    cout << cnt[i] << '\n';
    return 0;
}