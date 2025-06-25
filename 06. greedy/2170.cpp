#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct Pos{int x, y;};
vector<Pos> line;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        line.push_back({x, y});
    }

    sort(line.begin(), line.end(), [](const Pos &a, const Pos &b){
        return a.x < b.x; 
    });

    int len = 0;
    int cur_start = line[0].x, cur_end = line[0].y;
    for(int i=1; i < n; ++i){
        // 선이 겹치는 경우
        if(cur_end >= line[i].x){
            if(cur_end < line[i].y){
                cur_end = line[i].y;
            }
        }
        else{
            len += cur_end - cur_start;
            cur_start = line[i].x;
            cur_end = line[i].y;
        }
    }

    len += cur_end - cur_start;
    cout << len;
    
    return 0;
}