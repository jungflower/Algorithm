#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;

#if 0
long long reverse_arr(long long num) {
    long long rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<long long> v;

    int cnt = 0;
    long long num;
    while (cnt < n && cin >> num) {
        v.push_back(reverse_arr(num));
        cnt++;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        cout << v[i] << '\n';
    }

    return 0;
}
#endif

long long arr[1000002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0 ; i < n; ++i){
        string str;   cin >> str;
        reverse(str.begin(), str.end());
        arr[i] = stol(str);
    }
    sort(arr, arr+n);

    for(int i=0; i < n; ++i)    cout << arr[i] << '\n';
    return 0;
}