// 1992 쿼드트리
#include <iostream>
using namespace std;

int N;
string quad[64];

// 현재 (y, x) 위치에서 n x n 크기의 영역이 모두 같은 숫자인지 확인하는 함수
bool check(int y, int x, int n){
    for(int i=y; i < y+n; ++i){
        for(int j=x; j < x+n; ++j){
            if(quad[y][x] != quad[i][j])
                return false;
        }
    }
    return true;
}

void solve(int y, int x, int n){
    if(check(y, x, n)){ // 모든 숫자 같으면 해당 숫자 출력
        cout << quad[y][x];
        return;
    }

    // 모두 같은 수가 아니라면, 
    // n/2 * n/2으로 영역 4등분 하여 재귀 
    cout << "(";
    solve(y, x, n/2); // 왼쪽 위
    solve(y, x+n/2, n/2); // 오른쪽 위
    solve(y+n/2, x, n/2); // 왼쪽 아래
    solve(y+n/2, x+n/2, n/2); // 오른쪽 아래
    cout << ")";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; ++i){
        cin >> quad[i];
    }
    solve(0, 0, N);
    
    return 0;
}