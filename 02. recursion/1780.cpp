// 1780 종이의 개수
// 내가 못품...
#include <iostream>
using namespace std;

int n;
int paper[2200][2200];
int cnt[3]; // -1 0 1 수

// 해당 종이 내부에 같은 숫자로만 채워져있는지 확인하는 함수
bool check(int y, int x, int z){
    for(int i=y; i < y+z; ++i){
        for(int j=x; j < x+z; ++j){
            if(paper[y][x] != paper[i][j])
                return false;
        }
    }
    return true;
}

void solve(int y, int x, int z){
    // 같은 숫자로만 채워져있으면 cnt 추가
    if(check(y, x, z)){
        cnt[paper[y][x] + 1]++;
        return;
    }
    int N = z / 3;
    // 9등분으로 나눠서 다시 재귀 탐색 
    for(int i=0; i < 3 ; ++i){
        for(int j=0; j < 3; ++j){
            solve(y + i*N, x + j*N, N);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int y=0; y < n; ++y)
        for(int x=0; x < n; ++x)
            cin >> paper[y][x];
    
    solve(0, 0, n);
    for(int i=0; i < 3 ;i++)    cout << cnt[i] << '\n';
    return 0;
}