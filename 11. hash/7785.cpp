#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    unordered_set<string> s;
    for (int i = 0; i < n; ++i) {
        string name, state;
        cin >> name >> state;
        if (state == "enter") {
            s.insert(name);
        }
        else {
            s.erase(name);
        }
    }

    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a > b;
        });
    for (auto a : v) cout << a << '\n';

    return 0;
}