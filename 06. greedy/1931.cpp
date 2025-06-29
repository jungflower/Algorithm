/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct Time{int start; int end;};
Time info[100000];

// bool compare(const time &a, const time &b){
//     return a.end < b.end;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i < n; ++i)
        cin >> info[i].start >> info[i].end;

    // 끝나는 시간 기준으로 내림차순으로 정렬
    //sort(info, info+n, compare);
    sort(info, info+n, [](const Time &a, const Time &b){
        if(a.end == b.end)  return a.start < b.start;
        return a.end < b.end;
    });

    int min_time = info[0].end;
    int ans = 1; // 첫번째 요소 포함
    for(int i=1; i < n; ++i){
        if(min_time <= info[i].start){
            ans++;
            min_time = info[i].end;
        }
    }
    cout << ans;

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> time;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    time.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)    return a.first < b.first;
        return a.second < b.second;
        });

    int t = time[0].second, ans = 1;
    for (int i = 1; i < n; ++i) {
        if (time[i].first >= t) {
            ans++;
            t = time[i].second;
        }
    }
    cout << ans;

    return 0;
}