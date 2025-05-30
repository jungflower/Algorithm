#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int board[52][52];
struct Pos { int y; int x; };
vector<Pos> chickenPos; // 치킨집 좌표
int isused[15]; // 치킨집 사용 여부 저장
int res[52][52]; // 각 도시 정보
int ans = 1e9; // 치킨 거리 최솟값

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2)    chickenPos.push_back({ i, j });
        }
    }
}


// 선택한 치킨집과의 치킨 거리 최솟값
int solve(vector<int>& chicken) {
    int res = 0;
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            // 집이면 모든 치킨집과의 거리를 구하기 
            if (board[y][x] == 1) {
                int tmp = 1e9;
                for (auto dir : chicken) {
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
void dfs(int idx, int start, vector<int>& chicken) {
    if (idx == m) {
        int res = solve(chicken);
        ans = min(res, ans);
        return;
    }

    for (int i = start; i < chickenPos.size(); ++i) {
        if (!isused[i]) {
            chicken.push_back(i);
            isused[i] = 1;
            dfs(idx + 1, i + 1, chicken);
            isused[i] = 0;
            chicken.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    vector<int> chicken;
    dfs(0, 0, chicken);
    cout << ans << '\n';

    return 0;
}