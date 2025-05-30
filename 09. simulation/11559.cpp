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

#if 0
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

char board[12][6];
char color[5] = { 'R', 'G', 'B', 'P', 'Y' };
struct Pos { int y, x; };
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int ans;

void input() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> board[i][j];
        }
    }
}

// bfs
bool bfs(int y, int x, char color) {
    // color 가지고 들어오지? 그럼 bfs 할때 같은 color로 탐색 하자나? 그럼 이걸 vector에 넣는거야 4개가 되든 안되든든
    // 그럼 while문 내부에 if문 넣으면 복잡해지자나? 그니까 일단 bfs는 탐색만 하는거야. 한 기능은 하나만 있어야돼
    // 그리고 bfs 빠져나오고 나서 vector 체크해서, 4 이상이면 다 '.' 으로 바꿔주고, true 반환. 아니면 false 반환. 이렇게 하면 훨씬 간단해.
    queue<Pos> q;
    bool discovered[12][6];
    // dfs는 거기 방문하자마자 발견시점이 되는데 -> bfs는 탐색 후에 발견하게되는거니까 ? dfs는 재귀
    memset(discovered, false, sizeof(discovered));

    vector<Pos> same_color;

    q.push({ y, x });
    discovered[y][x] = true;
    while (!q.empty()) {
        Pos here = q.front(); q.pop();
        // cout << here.y << ", " << here.x << endl;
        same_color.push_back(here);
        for (int d = 0; d < 4; ++d) {
            int yy = here.y + dy[d], xx = here.x + dx[d];
            if (yy < 0 || yy >= 12 || xx < 0 || xx >= 6) continue;
            if (!discovered[yy][xx] && board[yy][xx] == color) {
                discovered[yy][xx] = true;
                q.push({ yy, xx });
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
//보여줄거면 다 고쳐서보여줘야지. 지금 실행 하는게 너무 마음에 안듬 ㅠ.
// 전체 탐색하며 연쇄 여부. 이것도 좀 이상상
bool bfs2(int y, int x, char color) {
    queue<Pos> q;
    bool vis[12][6];
    memset(vis, false, sizeof(vis));
    q.push({ y, x });
    vis[y][x] = true;

    int cnt = 1;
    while (!q.empty()) {
        Pos cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (cnt >= 4) { // 디버깅한거야?
                for (int i = 0; i < 12; ++i) {
                    for (int j = 0; j < 6; ++j) {
                        if (vis[i][j] == true) {
                            cout << cnt << ' ' << i << ' ' << j << endl;
                            board[i][j] == '.';
                        }
                    }
                }
                return true;
            }
            if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
            if (vis[ny][nx]) continue;

            // 보드가 해당 컬러일 때,,
            if (board[ny][nx] == color) {
                cout << color << ' ' << ny << ',' << nx << endl;
                q.push({ ny, nx });
                vis[ny][nx] = 1;
                ++cnt;
            }
        }
    }
    return false;
}

// 뿌요를 내리는 함수
void down() {
    for (int x = 0; x < 6; ++x) {
        int emptyRow = 11;  // 가장 아래부터 채워나감
        for (int y = 11; y >= 0; --y) {
            if (board[y][x] != '.') {
                // 빈 공간이 아래에 있으면 뿌요를 내림!
                if (emptyRow != y) {
                    board[emptyRow][x] = board[y][x];
                    board[y][x] = '.';
                }
                --emptyRow;
            }
        }

    }
}

void solve() { // bfs 전체 돌고 -> . 으로 만들고 (모두 다) -> 그리고 down 해야됨
    while (true) {
        bool check = false;
        for (int y = 0; y < 12; ++y) {
            for (int x = 0; x < 6; ++x) {
                if (board[y][x] != '.' && bfs(y, x, board[y][x])) { // bfs 하나라도 true -> check true 됨, down실행. 전부 false -> 더이상 터지는거 없음 -> 빠져나옴/
                    check = true;
                }
            }
        }
        if (!check) break;
        else down();
        ++ans;
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

#endif