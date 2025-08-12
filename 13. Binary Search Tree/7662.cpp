#include <iostream>
#include <set>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        multiset<int> ms;
        while (k--) {
            char cmd; int val;
            cin >> cmd >> val;
            switch (cmd) {
            case 'I':
                ms.insert(val);
                break;
            case 'D':
                if (!ms.empty()) {
                    // 최솟값 삭제
                    if (val == -1) {
                        ms.erase(ms.begin());
                    }
                    // 최댓값 삭제
                    else {
                        auto it = ms.end();
                        ms.erase((prev(it)));
                    }
                }
                break;
            }
        }
        if (ms.empty())  cout << "EMPTY" << '\n';
        else {
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}