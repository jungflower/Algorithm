#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> jewel;
multiset<int> bag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int m, v;
        cin >> m >> v;
        jewel.push_back({ v, m });
    }
    // sort(jewel.begin(), jewel.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    //     return a > b;
    //     });
    sort(jewel.begin(), jewel.end(), greater<>()); // 내림차순 -> 보석 가장 큰거부터

    for (int i = 0; i < k; ++i) {
        int w;
        cin >> w;
        bag.insert(w);
    }

    long long ans = 0;
    for (auto j : jewel) {
        // 해당 주얼리에 담을 수 있는 가장 작은 가방 찾음.
        auto it = bag.lower_bound(j.second);
        if (it != bag.end()) {
            ans += j.first;
            bag.erase(it); // 가방 하나 사용 완료
        }
    }
    cout << ans;

    return 0;
}