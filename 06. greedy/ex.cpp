#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int cnt = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        cnt++; // 현재 그룹에 해당 모험가 포함
        if (cnt >= arr[i]) {
            res++;
            cnt = 0;
        }
    }
    cout << res;
    return 0;
}