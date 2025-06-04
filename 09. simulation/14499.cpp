#include <iostream>
#include <queue>
using namespace std;

int n, m, k;
// 주사위 위치
struct Pos {
    int y, x;
} dice_pos;

enum { TOP, NORTH, EAST, WEST, SOUTH, BOTTOM };
int dice[6];
int Map[22][22];

// 방향: 동 서 북 남
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void input() {
    cin >> n >> m;
    int y, x;
    cin >> y >> x >> k;
    dice_pos = { y, x };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> Map[i][j];
        }
    }
    return;
}

// 주사위 굴리기
void RollDice(int dir) {
    int tmp;
    switch (dir) {
    case 1: //동
        tmp = dice[TOP];
        dice[TOP] = dice[WEST];
        dice[WEST] = dice[BOTTOM];
        dice[BOTTOM] = dice[EAST];
        dice[EAST] = tmp;
        break;
    case 2: // 서
        tmp = dice[TOP];
        dice[TOP] = dice[EAST];
        dice[EAST] = dice[BOTTOM];
        dice[BOTTOM] = dice[WEST];
        dice[WEST] = tmp;
        break;
    case 3: // 북
        tmp = dice[TOP];
        dice[TOP] = dice[SOUTH];
        dice[SOUTH] = dice[BOTTOM];
        dice[BOTTOM] = dice[NORTH];
        dice[NORTH] = tmp;
        break;
    case 4: // 남
        tmp = dice[TOP];
        dice[TOP] = dice[NORTH];
        dice[NORTH] = dice[BOTTOM];
        dice[BOTTOM] = dice[SOUTH];
        dice[SOUTH] = tmp;
        break;
    }

}

void solve() {
    while (k--) {
        int dir;
        cin >> dir;
        int ny = dice_pos.y + dy[dir];
        int nx = dice_pos.x + dx[dir];

        // 범위 벗어나면 굴리기 pass
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        else {
            // 좌표 갱신 후, 주사위 굴리기
            dice_pos = { ny, nx };
            RollDice(dir);

            // 밑바닥 점수
            if (!Map[ny][nx]) {
                Map[ny][nx] = dice[BOTTOM];
            }
            else {
                dice[BOTTOM] = Map[ny][nx];
                Map[ny][nx] = 0;
            }
            cout << dice[TOP] << '\n';
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}