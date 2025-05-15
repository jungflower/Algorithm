#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100002];

int binary_search(int target){
    int st = 0;
    int en = n-1;
    while(st <= en){
        int mid = (st+en)/2;
        if(a[mid] < target){
            st = mid + 1;
        }
        else if(a[mid] > target){
            en = mid - 1;
        }
        else{ // target == a[mid] -> 수를 찾음
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i)    cin >> a[i];
    sort(a, a+n);
    cin >> m;

    while(m--){
        int t;
        cin >> t;
        //cout << binary_search(t) << '\n';
        cout << binary_search(a, a+n, t) << '\n';
    }

    return 0;
}