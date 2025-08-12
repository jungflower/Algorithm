#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Time { int h, m; };
Time t[3];
unordered_map<string, vector<Time>> p;
unordered_map<string, int> nickname;

Time parseTime(string s) {
    return { stoi(s.substr(0, 2)), stoi(s.substr(3, 2)) };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    string S, E, Q;
    cin >> S >> E >> Q;

    string ti, name;
    int ans = 0;
    while (cin >> ti >> name) {
        // 시작 전 입장
        if (ti <= S) {
            nickname[name] = 1;
        }
        else if (ti >= E && ti <= Q) {
            if (nickname[name] == 1)
            {
                nickname[name] = 2;
                ++ans;
            }
        }
    }
    cout << ans;

    // 문자열 파싱해서 푼 풀이
#if 0
    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        t[i] = parseTime(s);
    }

    string name, ti;
    int ans = 0;
    while (cin >> ti >> name) {
        Time now;
        now = parseTime(ti);
        // 시작 시간 전 = 입장 여부 확인
        if (t[0].h > now.h || ((t[0].h == now.h) && t[0].m >= now.m)) {
            p[name].push_back(parseTime(ti));
            //cout << "start: " << ti << " " << name << '\n';
        }
        // 개총 끝나고 스트리밍 끝나기 전까지 = 퇴장 여부 확인
        if ((now.h < t[2].h || (now.h == t[2].h && now.m <= t[2].m)) &&
            (now.h > t[1].h || (now.h == t[1].h && now.m >= t[1].m))) {
            if (p.find(name) != p.end()) {
                ans++;
                p.erase(name);
                //cout << "end: " << ti << " " << name << '\n';
            }
        }
    }
    cout << ans;
#endif
    return 0;
}