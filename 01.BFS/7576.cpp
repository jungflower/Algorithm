#include <bits/stdc++.h>
using namespace std;

#define X first  
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int board[1002][1002];
int dist[1002][1002];

queue<pair<int, int>> q;

void input()
{
    cin >> m >> n;
    for(int i=0; i < n; i++){
        for(int j=0; j < m ;j++){
            cin >> board[i][j];
            if(board[i][j] == 1){ // 시작점을 모두 큐에 넣고 시작~
                q.push({i, j});
            }
            if(board[i][j] == 0){
                dist[i][j] = -1; // 익지않은 토마토는 -1로 구분
            }
        }
    }
    return;
}

void bfs(){
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir=0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 토마토가 없거나, 이미 방문한 곳이면 넘김
            if(dist[nx][ny] >= 0)   continue;
            cout << nx << ' ' << ny << '\n';
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 거리 계산
            q.push({nx, ny});
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();

    int res = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(dist[i][j] < 0){
                cout << -1;
                return 0;
            }
            res = max(res, dist[i][j]);
        }
    }
    cout << res;
    return 0;
}