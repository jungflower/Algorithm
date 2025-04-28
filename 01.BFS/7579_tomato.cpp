#include <bits/stdc++.h>
using namespace std;

int n, m, h; // n = 행, m = 열
int board[103][103][103];
int dist[103][103][103];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                int tmp;
                cin >> tmp;
                board[j][k][i] = tmp; // 올바르게 할당
                if (tmp == 1)
                    Q.push({j, k, i});    // 익은 토마토는 큐에 모두 넣기
                if (tmp == 0)
                    dist[j][k][i] = -1; //  익지 않은 토마토는 -1로 초기화
            }
        }
    }

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur; // 튜플로 묶인 변수 cu의 값을 각각의 변수인 curX, curY, curZ로 넣어줌
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (dist[nx][ny][nz] >= 0)
                continue; // 익었거나, 토마토가 아예 없는 경우
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({nx, ny, nz});
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dist[j][k][i] == -1)
                { // 안익은 토마토 남은 경우
                    cout << -1 << "\n";
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}