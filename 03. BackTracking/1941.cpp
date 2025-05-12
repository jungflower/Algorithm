// 1941 소문난 칠공주 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[5][5]; // Y, S 저장하는 보드 
int isused[25]; // 조합 -> 7명 뽑을 때 사용 여부 판단
int ans; 

struct Pos{int y; int x; };
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void input(){
    for(int i=0; i < 5; ++i){
        string str;
        cin >> str;
        for(int j=0; j < 5; ++j){
            if(str[j] == 'Y')   board[i][j] = 1;
            if(str[j] == 'S')   board[i][j] = 2;
        }
    }
}

// 4명 이상 있는지 확인
bool ismore4(){
    int Y_cnt=0, S_cnt=0;
    for(int i=0; i < 25; ++i){
        if(isused[i]){
            int y = i / 5;
            int x = i % 5;
            if(board[y][x] == 1)   Y_cnt++;
            if(board[y][x] == 2)   S_cnt++;
        }
    }
    return (S_cnt >= 4);
}

// 7명 서로 인접한지 확인(BFS)
bool adjency(){
    queue<Pos> q;
    int vis[5][5] = {0, }; // 방문 여부 저장
    
    // 7명 위치 좌표 저장
    vector<Pos> sel;
    for(int i=0; i < 25; ++i){
        if(isused[i]){
            sel.push_back({i/5, i%5});
        }
    }

    q.push(sel[0]);
    vis[sel[0].y][sel[0].x] = 1;

    int cnt = 1; // 연결된 요소 수 
    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)  continue;
            if(vis[ny][nx]) continue;

            // ny, nx가 현재 뽑힌 7명에 포함되는지 확인
            for(const Pos& p : sel){
                if(p.y == ny && p.x == nx && !vis[ny][nx]){
                    vis[ny][nx] = 1;
                    q.push({ny, nx});
                    ++cnt;
                }
            }

        }
    }
    return (cnt==7);
}


// 25명 중 7명 뽑기
void dfs(int idx, int k){
    if(k == 7){
        if(ismore4() && adjency()){
            ans++;
        }
        return;
    }

    for(int i=idx; i < 25; ++i){
        if(!isused[i]){
            isused[i] = 1;
            dfs(i, k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    dfs(0, 0);
    cout << ans;
    return 0;
}