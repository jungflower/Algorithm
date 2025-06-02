# 시뮬레이션  
## 예제  
### 15683_감시  
```
혼자 풀어봤을 땐 풀지 못한 점  
-> CCTV 각 방향에 대해 선택하는 것을 백트래킹으로 구현할 생각조차 못함 (복습 필요한듯,,)
-> 그리고 특히, 2번 좌우 상하만 있는거나 5번에서 모든방향 다보는 것을 BFS를 어떻게 돌려 확인해야될지 감이 안왔음 구현하는 법이 어려웠다,,
```

```cpp  
// 15683 감시
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
```  
**알고리즘 설계**  
1. CCTV 각 방향 정하기  
진법을 활용하여 CCTV는 4방향이기에, CCTV가 k개일 때 4^k - 1에 대한 방향을 정해주면 됨!  
![alt text](image.png)  

2. 정한 방향에 대해서 사각 지대의 크기를 구하기  

```cpp
// 15683_감시 
//-> 다시 풀어보기!
#include <iostream>
#include <vector>
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

```

1. 입력 받아 CCTV 위치 파악  
2. 각 CCTV마다 가능한 방향 조합을 백트래킹으로 순열 생성  
3. 각 조합마다 감시 시뮬레이션 수행  
4. 사각지대 최소값 계산  
5. 최소 사각지대 출력  

### 15686_치킨배달  
```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int board[52][52];
struct Pos {int y; int x;};
vector<Pos> chickenPos; // 치킨집 좌표
int isused[15]; // 치킨집 사용 여부 저장
int res[52][52]; // 각 도시 정보
int ans = 1e9; // 치킨 거리 최솟값

void input(){
    cin >> n >> m;
    for(int i=1; i <= n; ++i){
        for(int j=1; j <= n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 2)    chickenPos.push_back({i, j});
        }
    }
}


// 선택한 치킨집과의 치킨 거리 최솟값
int solve(vector<int>& chicken){
    int res = 0;
    for(int y=1; y <= n; ++y){
        for(int x=1; x <= n; ++x){
            // 집이면 모든 치킨집과의 거리를 구하기 
            if(board[y][x] == 1){
                int tmp = 1e9;
                for(auto dir : chicken){
                    int path = abs(y - chickenPos[dir].y) + abs(x - chickenPos[dir].x);
                    tmp = min(tmp, path);
                }
                res += tmp;
            }    
        }
    }

    return res;
}

// 치킨 집 m개 선택
void dfs(int idx, int start, vector<int>& chicken){
    if(idx == m){
        int res = solve(chicken);
        ans = min(res, ans);
        return;
    }

    for(int i=start; i < chickenPos.size(); ++i){
        if(!isused[i]){
            chicken.push_back(i);
            isused[i] = 1; 
            dfs(idx+1, i+1, chicken);
            isused[i] = 0;
            chicken.pop_back();
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    vector<int> chicken;
    dfs(0, 0, chicken);
    cout << ans << '\n';

    return 0;
}
```

### 11559_Puyo Puyo
```cpp
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char board[12][6];
int ans;
struct Pos { int y, x; };
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

void input() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> board[i][j];
        }
    }
}

//  뿌요 탐색 하는 함수 
bool bfs(int y, int x, char color) {
    queue<Pos> q;
    vector<Pos> same_color;
    bool discovered[12][6];
    memset(discovered, false, sizeof(discovered));

    q.push({ y, x });
    discovered[y][x] = true;
    same_color.push_back({ y, x });

    while (!q.empty()) {
        Pos cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
            if (!discovered[ny][nx] && board[ny][nx] == color) {
                q.push({ ny, nx });
                same_color.push_back({ ny, nx });
                discovered[ny][nx] = true;
            }
        }
    }

    if (same_color.size() >= 4) {
        for (Pos p : same_color) {
            board[p.y][p.x] = '.';
        }
        return true;
    }
    else {
        return false;
    }
}

// 뿌요 내리는 함수 
void down() {
    for (int x = 0; x < 6; ++x) {
        int emptyRow = 11;
        for (int y = 11; y >= 0; --y) {
            // 색깔인 부분 아래 . 이있는지 emptyrow로 판단
            if (board[y][x] != '.') {
                if (emptyRow != y) {
                    board[emptyRow][x] = board[y][x];
                    board[y][x] = '.';
                }
                --emptyRow;
            }
        }
    }
}

void solve() {
    while (1) {
        bool check = false;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                // 보드가 색깔인 부분에서 -> 탐색 했을 때 연쇄 파괴 여부 파악
                if (board[i][j] != '.' && bfs(i, j, board[i][j])) {
                    check = true;
                }
            }
        }

        if (!check)  break;
        else {
            down();
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}
```

### 14891_톱니바퀴  
알고리즘 설계  
1. input 입력 : 문자열로 입력받고, 정수로 변환해서 각 값을 저장  
2. 톱니바퀴 방향 정하기: setDirection()
3. 방향에 맞춰 회전하는 함수: rotate()

```cpp
#include <iostream>
#include <vector>
using namespace std;

int wheel[4][8];

void input() {
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            wheel[i][j] = s[j] - '0';
        }
    }
}

void rotate(int dir[]) {
    for (int num = 0; num < 4; ++num) {
        // 시계 방향
        if (dir[num] == 1) {
            int last = wheel[num][7];
            for(int i=7; i > 0; --i){
                wheel[num][i] = wheel[num][i-1];
            }
            wheel[num][0] = last;
        }
        // 반시계 방향 
        else if (dir[num] == -1) {
            int first = wheel[num][0];
            for(int i = 0; i < 7; ++i){
                wheel[num][i] = wheel[num][i+1];
            }
            wheel[num][7] = first;
        }
    }
}

void setDirection(int start, int start_dir) {
    int dir[4] = { 0, }; // 각 톱니바퀴의 방향 저장
    dir[start] = start_dir;

    // 오른쪽 방향으로 각 톱니바퀴 방향 비교
    for (int num = start; num < 3; ++num) {
        if (wheel[num][2] != wheel[num + 1][6]) {
            if (dir[num] == 1)  dir[num + 1] = -1;
            else if (dir[num] == -1)    dir[num + 1] = 1;
        }
    }

    // 왼쪽 방향으로 각 톱니바퀴 방향 비교
    for (int num = start; num > 0; --num) {
        if (wheel[num][6] != wheel[num - 1][2]) {
            if (dir[num] == 1)  dir[num - 1] = -1;
            else if (dir[num] == -1)    dir[num - 1] = 1;
        }
    }
    rotate(dir);
    return;
}

void solve() {
    int k;
    cin >> k;
    while (k--) {
        int start, dir; // 1 시계, -1 반시계 
        cin >> start >> dir;
        setDirection(start - 1, dir);
    }

    int ans = 0;
    for (int num = 0; num < 4; ++num) {
        switch (num) {
        case 0:
            if (wheel[num][0])   ans += 1;
            break;
        case 1:
            if (wheel[num][0])   ans += 2;
            break;
        case 2:
            if (wheel[num][0])   ans += 4;
            break;
        case 3:
            if (wheel[num][0])   ans += 8;
            break;
        }
    }
    cout << ans << '\n';
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}
```

