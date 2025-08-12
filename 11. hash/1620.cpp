#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    unordered_map<string, int> p1;
    unordered_map<int, string> p2;
    for (int i = 1; i <= n; ++i) {
        string name;
        cin >> name;
        p1[name] = i;
        p2[i] = name;
    }

    for (int i = 0; i < m; ++i) {
        string input;
        cin >> input;

        stringstream ss(input);
        int number;
        // 숫자 
        if (ss >> number && ss.eof()) {
            cout << p2[number] << '\n';
        }
        else { // 문자
            cout << p1[input] << '\n';
        }
    }

    return 0;
}