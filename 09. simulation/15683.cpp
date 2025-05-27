#include <iostream>
using namespace std;

struct Pos{int y; int x;};
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1}; // 남 동 북 서
int n, m;
int board[10][10]; // 사무실 입력 값
int map[10][10];

void input(){
    cin >> n >> m;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();

    return 0;
}