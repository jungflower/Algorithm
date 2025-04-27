#include <iostream>
using namespace std;

bool isused1[40]; // column을 차지하고 있는지
bool isused2[40]; // / 방향 대각선 차지하고 있는지 -> x+y 같음! ex) (1,0) (0,1)
bool isused3[40]; // \ 방향 대각선 차지하고 있는지 -> x-y 같음! ex) (0,2) (1,3)

int n, cnt;
void func(int cur){
    if(cur == n){ // n개 놓는데 성공
        cnt++;
        return;
    }
    for(int i = 0; i < n; ++i){ // (cur, i)에 퀸을 놓을 예정
        // column이나 대각선에 문제있다면 pass
        // issued3: 음수 인덱스를 만들지 않기 위해 n-1 더함 (x-y의 최솟값이 -(n-1)이기 때문)
        if(isused1[i] || isused2[i+cur] || isused3[cur-i+(n-1)])  continue;
        isused1[i] = 1;
        isused2[i+cur] = 1;
        isused3[cur-i+(n-1)] = 1;
        func(cur+1); // 다음 열 탐색
        isused1[i] = 0;
        isused2[i+cur] = 0;
        isused3[cur-i+n-1] = 0;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    func(0);
    cout << cnt;
    return 0;
}