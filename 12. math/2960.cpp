#include <iostream>
using namespace std;

int n, k, ans;
int a[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 2; i <= n; ++i)    a[i] = i;

    int cnt = 0, ans = 0;

    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0)   continue;
        // P의 배수를 크기 순서대로 지우기
        for (int j = i; j <= n; j += i) {
            if (a[j] == 0)   continue;
            a[j] = 0;
            cnt++;
            if (cnt == k) {
                cout << j << '\n';
                return 0;
            }
        }
    }
    return 0;
}