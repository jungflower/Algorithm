#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct Date { int start, finish; };
vector<Date> date;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        // 정확한 날짜를 계산할 필요가 없으므로, 임의로 계산
        date.push_back({ sm * 100 + sd, em * 100 + ed });
    }

    // 시작 날짜대로 정렬
    sort(date.begin(), date.end(), [](const Date& a, const Date& b) {
        if (a.start == b.start)  return a.finish < b.finish;
        else    return a.start < b.start;
        });

    int cnt = 0;
    int cur = 301;
    int max_date = 1130;
    int idx = 0;

    // 3월 1일 부터 11월 30일까지 매일 꽃이 한 가지 이상 피어있도록 
    while (cur <= max_date) {
        // 현재 날짜까지 피어있는 꽃 중에서 지는 날짜가 가장 늦은 꽃을 선택 
        int max_end = cur;
        while (idx < n && date[idx].start <= cur) {
            max_end = max(max_end, date[idx].finish);
            idx++;
        }

        // 11 30일이 되기전에 지는 날짜가 가장 늦은 꽃을 선택할 게 없으면 연결 불가
        if (max_end == cur) {
            cout << 0 << '\n';
            return 0;
        }

        cur = max_end;
        cnt++;
    }

    cout << cnt << '\n';
    return 0;
}