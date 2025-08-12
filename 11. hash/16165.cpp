#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n, m;
unordered_map<string, vector<string>> group_to_mem;
unordered_map<string, string> mem_to_group;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (n--) {
        string name; int num;
        cin >> name >> num;
        while (num--) {
            string mem;
            cin >> mem;
            group_to_mem[name].push_back(mem);
            mem_to_group[mem] = name;
        }
        sort(group_to_mem[name].begin(), group_to_mem[name].end());
    }


    while (m--) {
        string s; int num;
        cin >> s >> n;
        if (n == 1) { // 멤버 -> 그룹
            cout << mem_to_group[s] << '\n';
        }
        else { // 그룹 -> 멤버
            for (const auto& mem : group_to_mem[s]) {
                cout << mem << '\n';
            }
        }
    }

    return 0;
}