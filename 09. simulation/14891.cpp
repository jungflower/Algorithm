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
            for (int i = 7; i > 0; --i) {
                wheel[num][i] = wheel[num][i - 1];
            }
            wheel[num][0] = last;
        }
        // 반시계 방향 
        else if (dir[num] == -1) {
            int first = wheel[num][0];
            for (int i = 0; i < 7; ++i) {
                wheel[num][i] = wheel[num][i + 1];
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
            dir[num + 1] = -dir[num];
        }
        else    break; // 극 같으면 전파 멈춤
    }

    // 왼쪽 방향으로 각 톱니바퀴 방향 비교
    for (int num = start; num > 0; --num) {
        if (wheel[num][6] != wheel[num - 1][2]) {
            dir[num - 1] = -dir[num];
        }
        else    break;
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
        if (wheel[num][0])   ans += (1 << num);
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