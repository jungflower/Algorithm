// 2206 벽 부수고 이동하기
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Pos{int y, x, broken;}; // 방문했는지에 대한 여부
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int n,m;
string board[1001];
int vis[1001][1001][2]; // y x 벽 부순지를 저장하는 여부

void input(){
    cin >> n >> m;
    for(int y=0; y < n; ++y){
        cin >> board[y];
    }
    return;
}

void bfs(){
    queue<Pos> q;
    q.push({0, 0, 0});
    vis[0][0][0] = 1;

    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        for(int dir=0; dir < 4; ++dir){
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            int broken = cur.broken;
            if(ny < 0 || nx < 0 || ny >=n || nx >= m)   continue;

            // 빈칸일 때
            if(board[ny][nx] == '0' && vis[ny][nx][broken] == 0){
                vis[ny][nx][broken] = vis[cur.y][cur.x][broken] + 1;
                q.push({ny, nx, broken});
            }

            // 벽일 때 아직 안부쉈을때
            if(board[ny][nx] == '1' && broken == 0 && vis[ny][nx][1] == 0){
                vis[ny][nx][1] = vis[cur.y][cur.x][0] + 1;
                q.push({ny, nx, 1});
            }
        }
    }

    int ans = 0;
    if(vis[n-1][m-1][0] && vis[n-1][m-1][1]){
        ans = min(vis[n-1][m-1][0], vis[n-1][m-1][1]);
    }
    else{
        ans = max(vis[n-1][m-1][0], vis[n-1][m-1][1]);
    }
    cout << (ans == 0 ? -1 : ans);
    return; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();

    return 0;
}