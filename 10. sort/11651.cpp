#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
struct Pos {int x, y;};
vector<Pos> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        int y, x;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), [](const Pos& a, const Pos& b){
        if(a.y != b.y) return a.y < b.y;
        else    return a.x < b.x;
    });

    for(const Pos& p : v){
        cout << p.x << ' ' << p.y << '\n';
    }

    return 0;
}