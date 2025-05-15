# 그리디
지금 가장 최적이니 답을 근시안적으로 택하는 알고리즘  
= 관찰을 통해 탐색 범위를 줄이는 알고리즘  

### 알고리즘 순서
1. 관찰을 통해 탐색 범위를 줄이는 방법을 고안한다.  
2. 탐색 범위를 줄여도 올바른 결과를 낸다는 강한 믿음을 가진다.
3. 믿음을 가지고 구현해서 문제를 통과한다.  

## 예제
### 11047_동전 0
동전 가치 Ai가 Ai-1의 배수라는 조건 -> 그리디를 가능하게 해줌
**알고리즘**
1. 가치의 합 k를 만들기 위한 동전 개수 최솟값은 가장 높은 금액의 동전부터 사용하도록 탐색
```cpp
#include <iostream>
using namespace std;

int n, k;
int a[15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> n >> k;
    for(int i=0; i < n; ++i)
        cin >> a[i];
    
    for(int i=n-1; i >=0; --i){
        ans += k / a[i];
        k %= a[i];
    }
    cout << ans;
    return 0;
}
```

### 1931_회의실 배정 
-> 가능한 회의 중에서 가장 먼저 끝나는 회의 택하기!

// 내가 짠 코드 // 
-> 람다 함수 사용법 익히기 (두번째 요소로 정렬) -> 중복 조건도 고려!
-> 
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct Time{int start; int end;};
Time info[100000];

// bool compare(const time &a, const time &b){
//     return a.end < b.end;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i=0; i < n; ++i)
        cin >> info[i].start >> info[i].end;
    
    // 끝나는 시간 기준으로 내림차순으로 정렬
    //sort(info, info+n, compare);
    sort(info, info+n, [](const Time &a, const Time &b){
        // 끝나는 시간 동일하다면 시작하는 시간으로 배치
        // 시작하자마자 끝나는 회의의 존재 떄문 !
        if(a.end == b.end)  return a.start < b.start;
        return a.end < b.end;
    });

    int min_time = info[0].end;
    int ans = 1; // 첫번째 요소 포함 
    for(int i=1; i < n; ++i){
        if(min_time <= info[i].start){
            ans++;
            min_time = info[i].end;
        }
    }
    cout << ans;

    return 0;
}
```

// 다른 코드 //
```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> s[100005]; // schedule, 정렬의 편의를 위해 {끝 시간, 시작 시간}으로 저장

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> s[i].second >> s[i].first;
  sort(s,s+n); // 먼저 끝나는 시간을 비교하고, 끝나는 시간이 동일하면 시작 시간 순으로 정렬
  int ans = 0;
  int t = 0; // 현재 시간
  for(int i = 0; i < n; i++){
    if(t > s[i].second) continue; // 시작 시간이 현재 시간보다 이전인 회의라면 무시
    ans++; // 시작 시간이 현재 시간 이후인 회의를 찾았으므로 회의의 수에 1 증가
    t = s[i].first; // 현재 시간을 s[i]의 끝나는 시간으로 변경한다.
  }
  cout << ans;
}
```

### 2217_로프
-> 모든 로프 조합 고려하면 $2^n$
-> 최대 중량이 가장 낮은 
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> w;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    w.resize(n);
    for(int i=0; i < n; ++i){
        cin >> w[i];
    }

    sort(w.begin(), w.end());
    int res = 0;
    for(int i=1; i <= n; ++i){
        res = max(res, w[n-i]*i);
    }
    cout << res;
    
    return 0;
}
```

### 12865_평범한 배낭  
-> 이 문제는 그리디로 최대의 가치대로 정렬한 후, 가치대로 물건들의 최댓값을 구하면 될거 같지만, 실제로는 반례가 생김 
==> 물건을 분할할 수 있다면 그리디 알고리즘이 최적해를 보장했을 것!
-> 따라서 DP가 방법!