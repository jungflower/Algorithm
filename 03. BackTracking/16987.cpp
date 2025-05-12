#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
struct Info{ int s; int w; };
Info egg[10];

void func(int k){
    if(k == n){
        int broken = 0;
        for(int i=0; i < n; ++i){
            if(egg[i].s <= 0) ++broken;
        }
        res = max(res, broken);
        return;
    }

    // 현재 계란이 이미 깨졌다면 바로 다음 계란 이동
    if(egg[k].s <= 0){
        func(k+1);
        return;
    }

    bool check = false;
    for(int i=0; i < n; ++i){
        // 손에 든 계란이거나, 이미 깨진 계란이면 패스
        if(i == k || egg[i].s <= 0) continue; 

        // 계란 칠 때,
        egg[k].s -= egg[i].w;
        egg[i].s -= egg[k].w;
        check = true;
        // 다음 계란 이동
        func(k+1);
        // 원상 복구
        egg[k].s += egg[i].w;
        egg[i].s += egg[k].w;
    }
    // 계란 모두 깨진 상황(현재 계란은 남아있고)
    if(!check)  func(k+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i){
        cin >> egg[i].s >> egg[i].w;
    }
    func(0);
    cout << res;
    return 0;
}