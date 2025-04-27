# 백트래킹(BackTracking)
현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘
= 재귀적으로 문제를 해결하며, 재귀를 통해 확인 중인 상태가 제한 조건에 위배가 되는지 판단하고, 해가 도저히 안된다고 판단되면 그 전 단계로 되돌아가 다시 해를 찾음!
-> DFS로 구현 가능
* DFS: 깊이 우선 탐색으로, 가능한 모든 경로를 탐색! -> 모든 경로를 탐색하기에, 불필요할 것 같은 경로 사전 차단 불가

## 알고리즘 순서 ##
### 15649_N과 M(1) ###
```cpp
#include <iostream>
using namespace std;

int n,m;
int arr[10];
int isused[10];

void func(int k){
    if(k == m){ // 현재 k개까지 수를 택함
        for(int i=0; i < m; ++i){
            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
        }
        cout << '\n';
        return;
    }

    for(int i=1; i <= n; ++i){
        if(!isused[i]){ // 아직 i가 사용되지 않았으면
            arr[k] = i; // k번째 수를 i로 정함
            isused[i] = 1; // i 사용되었다고 표시
            func(k+1); // 다음 수 정하러 한단계 더 들어가기
            isused[i] = 0; // k번째 수를 i로 정한 모든 경우를 확인했으니 i를 이제 사용하지 않는다고 반환
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // n: 숫자, m: 택할 수
    func(0);

    return 0;
}
```
### next_permutation (STL)
```cpp
int a[3] = {1,2,3};
do{
    for(int i=0; i < 3; ++i)
        cout << a[i];
    cout << '\n';
}while(next_permutation(a, a+3));
// 123
// 132
// 213
// 231
// 312
// 321

```  
-> 현재 배열을 기준으로 다음 순열을 만들어주는 함수
   다음 순열이 없다면 false를 리턴, 배열은 오름차순으로 정렬  
 `bool next_permutation(시작주소, 끝주소)`


## 예제 ##
### 9663_N-Queen ### 
-> 백트래킹 이해하고 다시 혼자 풀어보기
```cpp
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
```

### 1182_부분 수열의 합
-> 다시 풀어보기

```cpp
// 1182 부분수열의 합
// -> 다시 풀어보기
// 부분 수열의 합 = 2^n - 1 (-1은 공집합)
#include <iostream>
using namespace std;

int N, S;
int arr[25];
int sum, cnt;

void func(int cur, int sum){
    if(cur == N){
        if(sum == S)    ++cnt;
        return;
    }
    func(cur+1, sum); // 현재 원소 안쓰고 넘어가기
    func(cur+1, sum + arr[cur]); // 현재 원소를 선택해서 합에 추가
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i=0; i < N; ++i)    cin >> arr[i];
    func(0, 0);
    if(S == 0)  cnt--; // 공집합 제외
    cout << cnt;
    return 0;
}
```

### 15650_N과 M(2)
https://www.acmicpc.net/problem/15650  
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
- 고른 수열은 오름차순이어야 한다.

```cpp
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
```

*다른 풀이*
-> next_permutation 사용
```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  // M의 개수만큼 0을 넣어줌
  for(int i = 0; i < N; ++i)  a.push_back(i < M ? 0 : 1);
  do{
    for(int i = 0; i < N; ++i)
    // 0을 넣은 자리에만 조합을 만들도록 조건 !
      if(a[i] == 0) cout << i+1 << ' ';
    cout << '\n';
  }while(next_permutation(a.begin(), a.end()));
}
```

### 15651_N과 M(3)
https://www.acmicpc.net/problem/15651  
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.  

- 1부터 N까지 자연수 중에서 M개를 고른 수열  
- 같은 수를 여러 번 골라도 된다.
```cpp
#include <iostream>
using namespace std;

int N, M;
int arr[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i <= N; ++i){
        arr[k] = i;
        func(k+1);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    func(0);
    return 0;
}
```
### 15652_N과 M(4)
https://www.acmicpc.net/problem/15652  
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.  

- 1부터 N까지 자연수 중에서 M개를 고른 수열  
- 같은 수를 여러 번 골라도 된다.  
- 고른 수열은 비내림차순이어야 한다.    
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.  
```cpp
#include <iostream>
using namespace std;

int N, M;
int arr[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i <= N; ++i){
        if(k == 0 || arr[k-1] <= i){
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
```

### 15654_N과 M(5)
https://www.acmicpc.net/problem/15654  
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

- N개의 자연수 중에서 M개를 고른 수열
```cpp
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
```




