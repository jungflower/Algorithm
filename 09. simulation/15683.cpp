// 15683 감시 - 바킹독 버전
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Pos{int y; int x;};
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1}; // 남 동 북 서
int n, m, blind_spot=1e9;
int board[10][10]; // CCTV map 입력 값
int vis[10][10]; // CCTV 지나간 방문 여부 저장
vector<Pos> cctv; // cctv 좌표 저장  

void input(){
    cin >> n >> m;
    for(int y=0; y < n; ++y){
        for(int x=0; x < m; ++x){
            cin >> board[y][x];
            // CCTV 좌표 저장: 6은 벽
            if(board[y][x] != 0 && board[y][x] != 6){
                cctv.push_back({y, x});
            }
            //if(board[y][x] == 0)   blind_spot++;
        }
    }
}

// CCTV 방향으로 탐색하는 함수
// (y, x)에서 dir방향으로 진행하면서 벽을 만날 때 까지 해당 방향으로, 
// 지나치는 모든 빈칸을 7로 변경! (지나갔다는 것을 표시)
void upd(int y, int x, int dir){
    dir %= 4; // 남동북서 돌기 때문
    while(1){
        y += dy[dir];
        x += dx[dir];
        // 범위 벗어나거나, 벽 만나면 return
        if(y < 0 || y >= n || x < 0 || x >= m || vis[y][x] == 6)  return;
        if(vis[y][x] == 0)   vis[y][x] = 7; // 빈칸 7로 덮어씀 
    }
}

// cctv 방향 정해서 cctv 탐색
void findblindspotByDirection(){
    // 4^k - 1 까지 반복 () -> cctv 방향 될 수 있는 토탈 경우의 수만큼 탐색
    // 각 자리수가, cctv 방향
    for(int tmp = 0; tmp < (1 << (2 * cctv.size())); ++tmp){
        for(int y = 0 ; y < n; ++y){
            for(int x = 0; x < m; ++x){
                vis[y][x] = board[y][x];
            }
        }
        int brute = tmp; // CCTV 방향 경우의 수 brute 변수에 넣기!
        for(int i=0; i < cctv.size(); ++i){
            int dir = brute % 4;
            brute /= 4;
            int y = cctv[i].y;
            int x = cctv[i].x;
            // cctv 방향에 따라 vis 배열 update
            if(board[y][x] == 1){
                upd(y, x, dir);
            }
            else if(board[y][x] == 2){
                upd(y, x, dir);
                upd(y, x, dir+2);
            }
            else if(board[y][x] == 3){
                upd(y, x, dir);
                upd(y, x, dir+1);
            }
            else if(board[y][x] == 4){
                upd(y, x, dir);
                upd(y, x, dir+1);
                upd(y, x, dir+2);
            }
            else{ // 양 방향
                upd(y, x, dir);
                upd(y, x, dir+1);
                upd(y, x, dir+2);
                upd(y, x, dir+3);
            }
        }
        int val = 0;
        for(int i=0; i < n; ++i){
            for(int j=0; j < m; ++j){
                val += (vis[i][j] == 0);
            }
        }
        blind_spot = min(val, blind_spot);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    findblindspotByDirection();

    cout << blind_spot;
    return 0;
}

#endif

// 15683_감시 
//-> 다시 풀어보기!
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int board[10][10]; // 입력
int copy_board[10][10]; // 감시 영역 처리용
int blind_spot = 1e9;

struct Pos{int y; int x;};
vector<Pos> cctv;

// 방향: 북 동 남 서
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 각 cctv별로 가능한 방향 세트
vector<vector<vector<int>>> cctv_dir = {
    {},
    {{0}, {1}, {2}, {3}},                          // 1번 CCTV
    {{0, 2}, {1, 3}},                              // 2번 CCTV
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},              // 3번 CCTV
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},  // 4번 CCTV
    {{0, 1, 2, 3}}                                 // 5번 CCTV
};

void input(){
    cin >> n >> m;
    for(int i=0; i < n; ++i){
        for(int j=0; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5){
                cctv.push_back({i, j});
            }
        }
    }
}


void fill(int y, int x, int dir){
    dir %= 4; // 방향 4개이기 때문 ~
    while(1){
        y += dy[dir];
        x += dx[dir];
        // 범위 벗어나거나, 벽 (6)을 만나면 빠져나오기
        if(y < 0 || y >= n || x < 0 || x >= m || copy_board[y][x] == 6)  break;
        if(copy_board[y][x] == 0){
            copy_board[y][x] = 7; // 감시 영역 표시
        }
    }
}

void simulate(vector<int>& dirs){
    // for(int i=0; i < n; ++i){
    //     for(int j=0; j < m; ++j){
    //         copy_board[i][j] = board[i][j];
    //     }
    // }
    memcpy(copy_board, board, sizeof(board));

    // 각 cctv에 대해 해당 방향으로 감시 영역 채우기
    for(int i=0; i < dirs.size(); ++i){
        int y = cctv[i].y;
        int x = cctv[i].x;
        int type = board[y][x];
        int dir_idx = dirs[i];

        for(int d: cctv_dir[type][dir_idx]){
            fill(y, x, d);
        }
    }

    // 사각지대 세기
    int cnt = 0;
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < m; ++x){
            if(copy_board[y][x] == 0)   ++cnt;
        }
    }
    blind_spot = min(cnt, blind_spot);
}

// 백트래킹으로, CCTV 방향 경우의 수
void dfs(int idx, vector<int>& dirs){
    if(idx == cctv.size()){
        simulate(dirs);
        return;
    }

    int y = cctv[idx].y;
    int x = cctv[idx].x;
    int type = board[y][x];

    for(size_t i=0; i < cctv_dir[type].size(); ++i){
        dirs.push_back(i);
        dfs(idx+1, dirs);
        dirs.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    vector<int> dir;
    dfs(0, dir);

    cout << blind_spot;
    return 0;
}
