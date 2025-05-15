#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500002];

// target이 시작되는 위치 
int lower_idx(int target, int len){
    int st = 0;
    int en = len; // 하나의 값 추가해서 넣을 거기 때문에 len

    // st != en 이 다를때까지 반복!
    while(st < en){
        int mid = (st+en)/2;
        if(arr[mid] >= target)  en = mid;
        else    st = mid+1; // arr[mid] < target : start가 mid+1이라고 가정
    }
    return st; // st = mid = en 되면 해당 인덱스는 값이 시작하는 첫 index 반환 
}

// target이 끝나는 위치
int upper_idx(int target, int len){
    int st = 0;
    int en = len;

    while(st < en){
        int mid = (st+en)/2;
        if(arr[mid] > target)  en = mid;
        else    st = mid+1; // arr[mid] <= target 
    }
    return st;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i)    cin >> arr[i];
    sort(arr, arr+n);

    cin >> m;
    while(m--){
        int t;
        cin >> t;
        //cout << upper_idx(t, n) - lower_idx(t, n) << ' ';
        // STL 이용
        cout << upper_bound(arr, arr+n, t)- lower_bound(arr, arr+n, t) << ' ';
    }

    return 0;
}