#include <bits/stdc++.h>
using namespace std;

int n,m;
string board[102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[102][102];

void input(){
    cin >> n >> m;
    for(int i=0; i < n; i++){
        cin >> board[i];
        fill(vis[i], vis[i]+m, -1); // vis -1로 채움
    }    
    
}

void bfs()
{
    queue<pair<int, int>> q;
    int flag = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(board[i][j] != '1') continue;
            vis[i][j] = 1;
            q.push({i, j});
            flag = 1;
            break;
        }
        if(flag)    break;
    }

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir=0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] != -1 || board[nx][ny] == '0') continue; // 방문한 적 있거나, 0이면 넘김
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            q.push({nx, ny});
            //cout << vis[nx][ny] << ' ' << nx << ' ' << ny << endl;
        }
    }
    cout << vis[n-1][m-1];
    return ;
}

int cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();

    return 0;
}