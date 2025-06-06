// 11652 카드
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int cnt = 0;
    int mx = 0;
    long long max_val = arr[0];
    for(int i = 0; i < n; ++i){
        if(arr[i] == arr[i-1]){
            cnt++;
        }
        else{
            cnt = 1;
        }

        if(cnt > mx){
            mx = cnt;
            max_val = arr[i];
        }
    }

    cout << max_val << '\n';
    return 0;
}
#endif
#include <iostream>
#include <map>
using namespace std;

int n;
map<long long, int> freq;  // key: 숫자, value: 빈도 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        freq[x]++;
    }

    long long most_freq_num = 0;
    int max_count = 0;

    for (auto &p : freq) {
        if (p.second > max_count) {
            max_count = p.second;
            most_freq_num = p.first;
        }
    }

    cout << most_freq_num << '\n';
    return 0;
}