#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int res[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i)    cout << res[i] << ' ';
        cout << '\n';
        return; 
    }

    int pre = -1;
    for(int i=0; i < N; ++i){
        if(pre != arr[i] && (k==0 || res[k-1] <= arr[i])){
            res[k] = arr[i];
            pre = arr[i];
            func(k+1);
        }
    }

}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i < N; ++i) cin >> arr[i];
    sort(arr, arr+N);
    func(0);
    return 0;
}