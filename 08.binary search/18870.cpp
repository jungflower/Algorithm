#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x[1000002];
vector<int> tmp, uni; // unique 중복 제거한 배열 

int lower_idx(int target, int len){
    int st = 0;
    int en = len;

    while(st < en){
        int mid = (st+en)/2;
        if(uni[mid] >= target)  en = mid;
        else    st = mid+1;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
#if 0
    // 1. 벡터 요소 값 넣기 
    for(int i=0; i < n; ++i){
        cin >> x[i];
        tmp.push_back(x[i]);
    }    
    // 2. 비교할 벡터 요소 값 정리
    sort(tmp.begin(), tmp.end());
    // 3. 중복 제거 벡터 
    for(int i=0; i < n; ++i){
        if(i==0 || tmp[i-1] != tmp[i])
            uni.push_back(tmp[i]);
    }

    // 4. 각 인덱스 값이 다른 좌표보다 더 큰값일 때의 갯수
    for(int i=0; i < n; ++i){
        //cout << lower_idx(x[i], uni.size()) << ' ';
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    }
#endif
    for(int i=0; i< n; ++i){
        cin >> x[i];
        uni.push_back(x[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for(int i=0; i < n; ++i){
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    }
    return 0;
}