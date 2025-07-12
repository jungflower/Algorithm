#include <iostream>
using namespace std;

int n, s;
int arr[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)    cin >> arr[i];

    int mn = 0x7fffffff;
    int sum = 0, st = 0;

    for (int en = 0; en < n; ++en) {
        sum += arr[en];
        while (sum >= s) {
            mn = min(mn, en - st + 1);
            sum -= arr[st++];
        }
    }
    cout << ((mn != 0x7fffffff) ? mn : 0) << '\n';

    return 0;
}