#include <iostream>
using namespace std;

int n;
int arr[100002], isused[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)    cin >> arr[i];

    int st = 0, en = 0;
    long long cnt = 0; // long long 주의!!!

    while (st < n) {
        while (en < n && !isused[arr[en]]) {
            isused[arr[en]] = 1;
            en++;
        }
        cnt += en - st;
        isused[arr[st]] = 0;
        st++;
    }
    cout << cnt << '\n';

    return 0;
}