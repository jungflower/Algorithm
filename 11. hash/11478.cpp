#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    unordered_set<string> us;

    // 완탐
    #if 0
    for (int i = 0; i < s.length(); ++i) {
        string tmp;
        tmp += s[i];
        us.insert(tmp);
        for (int j = i + 1; j < s.length(); ++j) {
            tmp += s[j];
            us.insert(tmp);
        }
    }
    #endif

    

    cout << us.size();
    return 0;
}