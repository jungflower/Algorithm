#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int R, C;
string board[1002]; // 미로 입력
int jtime[1002][1002]; // 지훈이의 시간
int ftime[1002][1002]; // 불에 대한 시간

void input(){
    cin >> R >> C;
    for(int i=0; i < R; i++){
        cin >> board[i];
        fill(ftime[i], ftime[i] + C, -1);
        fill(jtime[i], jtime[i] + C, -1);
    }

    return;
}

void fire_bfs(){
    queue<pair<int, int>> fq; // 불에 대한 dfs
    for(int i=0; i < R; i++){
        for(int j=0; j < C; j++){
            if(board[i][j] == 'F'){
                fq.push({i, j}); // 불의 시작점
                ftime[i][j] = 0;
            }
        }
    }

    while(!fq.empty()){
        pair<int, int> cur = fq.front(); fq.pop();
        for(int dir=0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            // 이미 방문한 곳이거나 . 이 아니면 pass
            if(ftime[nx][ny] >= 0 || board[nx][ny] != '.') continue;
            ftime[nx][ny] = ftime[cur.X][cur.Y] + 1;
            fq.push({nx, ny}); 
        }
    }
}

void jihoon_bfs(){
    queue<pair<int, int>> jq; // 지훈이에 대한 dfs
    for(int i=0; i < R; i++){
        for(int j=0; j < C; j++){
            if(board[i][j] == 'J'){
                jq.push({i, j}); // 지훈이의 시작점
                jtime[i][j] = 0;
            }
        }
    }
    
    while(!jq.empty()){
        pair<int, int> cur = jq.front(); jq.pop();
        for(int dir=0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 탈출한 경우 : 범위 벗어난 것은 탈출했다는 소리니까 ~
            if(nx < 0 || ny < 0 || nx >= R || ny >= C){
                cout << jtime[cur.X][cur.Y]+1;
                return;
            }
            // 이미 방문한 곳이거나 .이 아니면 pass
            if(jtime[nx][ny] >= 0 || board[nx][ny] != '.') continue;
            // 불에 의해 통과하지 못하는 경우 : 불이 이미 방문했거나 불이 먼저 도착한 경우
            if(ftime[nx][ny] >= 0 && ftime[nx][ny] <= jtime[cur.X][cur.Y] + 1) continue;
            jtime[nx][ny] = jtime[cur.X][cur.Y] + 1;
            jq.push({nx, ny}); 
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    fire_bfs();
    jihoon_bfs();

    return 0;
}