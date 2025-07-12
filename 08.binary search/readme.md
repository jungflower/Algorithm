# 이분 탐색  
정렬되어 있는 배열에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 탐색 방법

*주의사항*  
1. 이분 탐색을 하고자 한다면 주어진 배열은 정렬되어 있어야 한다.
2. 무한 루프에 빠지지 않게 mid값을 정해야 한다.  



## 예제
### 1920_수찾기
**STL**   
binary_search(a, a+n, t);

```cpp
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
```

### 10816_숫자카드2 
**STL**  
upper_bound(arr, arr+n, t): 마지막 위치 반환    
lower_bound(arr, arr+n, t): 첫번째 위치 반환  

```cpp
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
```  
### 18870_좌표 압축  
-> 원소 중복 제거 : `v.erase(unique(v.begin(), v.end()), v.end());`  

```cpp
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
```