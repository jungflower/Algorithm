#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N, M;
int arr[10];

void func(int k){
    if(k == M){ // idx가 M개가 된다면
        for(int i=0; i < M; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i <= N; ++i){
        // k가 0일때는 무조건 다 탐색 시작
        // k >= 1이면 arr[k-1] 보다 큰 숫자만 탐색
        if(k == 0 || (k >= 1 && arr[k-1] < i)){ 
            arr[k] = i;
            func(k+1);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(0);
    return 0;
}