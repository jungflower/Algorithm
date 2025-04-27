#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10]; // 자연수 N개 담은 배열
int isused[10]; // 값 사용했는지 여부
int res[10]; // M개 고른 수열

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i)
            cout << res[i] << ' ';
        cout << '\n';
        return; 
    }

    for(int i=0; i < N; ++i){
        if(!isused[i]){ // 사용한 값 아니면 ~
            res[k] = arr[i]; 
            isused[i] = 1;
            func(k+1);
            isused[i]=0;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    func(0);
    return 0;
}