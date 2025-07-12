#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n;
long long arr[5002];
long long ans[3] = { LLONG_MAX / 3, LLONG_MAX / 3, LLONG_MAX / 3 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)    cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // 0에 가까운 값을 찾는 것 ~~
            int idx = lower_bound(arr, arr + n, -(arr[i] + arr[j])) - arr;
            // idx가 i와 같고 다음 바로 j가 온다거나 / idx가 j와 같고 다음 바로 i가 온다면 
            // idx - 3 ~ idx + 2 까지 확인해보기
            // -3 포함 이유 
            /*
                arr = [-10, -5, 1, 3, 8, 9]
                i = 0, j = 1이라면 arr[i] + arr[j] = -15
                lower_bound(arr, arr + n, 15)는 idx = 6 → 범위 밖
            */
            for (int k = -3; k <= 2; ++k) {
                // 범위 벗어나면
                if (idx + k < 0 || idx + k >= n) continue;
                // idx + k가 i와 j와 겹치는 경우
                if (idx + k == i || idx + k == j) continue;
                if (abs(ans[0] + ans[1] + ans[2]) > abs(arr[i] + arr[j] + arr[idx + k])) {
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                    ans[2] = arr[idx + k];
                }
            }
        }
    }
    sort(ans, ans + 3);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << '\n';

    return 0;
}