#include <iostream>
#include <queue>
using namespace std;

#define X first 
#define Y second 

int n, m; // n: 행, m: 열
int num; // 그림의 개수
int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input(){
  cin >> n >> m;
  for(int i=0; i < n; i++){
    for(int j=0; j < m; j++){
      cin >> board[i][j];
    }
  }
  return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  input();

  int mx = 0; // 그림 넓이 최댓값
  for(int i=0; i < n; i++){
    for(int j=0; j < m; j++){
      if(!board[i][j] || vis[i][j]) continue;
      num++;
      queue<pair<int, int>> Q;
      vis[i][j] = 1;
      Q.push({i, j});
      int area = 0; // 그림 넓이
      while(!Q.empty()){
        area++;
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir < 4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(vis[nx][ny] || !board[nx][ny]) continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
        mx = max(mx, area);
      }
    }
  }
  cout << num << ' ' << mx;
 
  return 0;
}