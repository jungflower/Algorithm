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
### 15655 N과 M(6)
https://www.acmicpc.net/problem/15655  
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int isused[10];
int res[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i)
            cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i < N; ++i){
        if(!isused[i] && (k==0 || res[k-1] <= arr[i])){
            res[k] = arr[i];
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
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

### 15656 N과 M(7)
https://www.acmicpc.net/problem/15656
```cpp
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

    for(int i=0; i < N; ++i){
        res[k] = arr[i];
        func(k+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; ++i)    cin >> arr[i];
    sort(arr, arr+N);
    func(0);
    return 0;
}
```
### 15657 N과 M(8)
https://www.acmicpc.net/problem/15657
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int res[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i < N; ++i){
        if(k == 0 || res[k-1] <= arr[i]){
            res[k] = arr[i];
            func(k+1);
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i < N; ++i)    cin >> arr[i];
    sort(arr, arr+N);
    func(0);
    return 0;
}
```

### 15663_N과 M(9)
https://www.acmicpc.net/problem/15663  
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int res[10];
int isused[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i)    cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    int prev_val = -1;

    for(int i=0; i < N; ++i){
        if(!isused[i] && prev_val != arr[i]){
            res[k] = arr[i];
            isused[i] = 1;
            prev_val = arr[i];
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i < N; ++i)    cin >> arr[i];
    sort(arr, arr+N);
    func(0);
    return 0;
}
```

### 15664_N과 M(10)
https://www.acmicpc.net/problem/15664
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int res[10];
int isused[10];

void func(int k){
    if(k == M){
        for(int i=0; i < M; ++i)    cout << res[i] << ' ';
        cout << '\n';
    }

    int pre = -1;
    for(int i=0; i < N; ++i){
        if(!isused[i] && pre != arr[i] && (k == 0 || res[k-1] <= arr[i])){
            res[k] = arr[i];
            isused[i] = 1;
            pre = arr[i];
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i < N; ++i)    cin >> arr[i];
    sort(arr, arr+N);
    func(0);
    return 0;
}
```

### 15665_N과 M(11)
https://www.acmicpc.net/problem/15665  
```cpp
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
        if(pre != arr[i]){
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
    for(int i=0; i < N; ++i)    cin >> arr[i];
    sort(arr, arr+N);   
    func(0);

    return 0;
}
```

### 15666_N과 M(12)
https://www.acmicpc.net/problem/15666  
```cpp
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
```

### 1759_암호 만들기  
```cpp
// 1759 암호 만들기 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char res[20];
int isused[20];
vector<char> letter;

// 모음 여부와 자음2개 이상인지 판단하는 함수 
bool isvowel_word(){
    bool vowel_flag = false;
    int cnt=0; // 자음 수
    bool flag = false;
    for(int i=0; i < L; ++i){
        char vowel = res[i];
        if(vowel == 'a' || vowel == 'e' || vowel == 'i' 
            || vowel == 'o' || vowel == 'u')
                vowel_flag = true;
        else{
            ++cnt;
        }
    }
    if(cnt >= 2 && vowel_flag)  flag = true;
    return flag;    
}

void func(int k, int start){
    if(k == L){
        if(isvowel_word()){
            for(int i=0; i < L; ++i){
                cout << res[i];
            }
            cout << '\n';
        }
        return;
    }

    for(int i=start; i < C; ++i){
        res[k] = letter[i];
        func(k+1, i+1); // i+1로 다음 인덱스부터 탐색
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    letter.resize(C);

    for(int i=0; i < C; ++i){
        cin >> letter[i];
    }
    sort(letter.begin(), letter.end());         
    func(0, 0);
    return 0;
}
```  
**알고리즘 설계**  
1. 입력 받은 문자들 먼저 오름차순으로 정렬
2. 만들 글자수와, 시작할 인덱스를 가지고 백트래킹 시작
    - 시작할 인덱스부터 다음 인덱스부터만 탐색하여 다음 글자수 선택
    - 모음이 있고, 자음 2개 이상 있으면 문자열의 각 글자수 출력  

*기억해야할 점*
```cpp
for(auto vowel : res){
    ...
}
```
처음에 위 코드와 같이 배열의 요소를 순회했는데, 암호 생성은 L길이까지만 유효하기에, 초과된 공간까지 탐색하면 불필요한 데이터 포함됨  
-> 설계한대로 제대로 나오지 않음.... 유효한 길이만 탐색하도록 변경  

### 16987_계단으로 계란치기  
XX
백트래킹으로 모든 경우를 탐색해야 한다고 생각했지만, 조건을 제대로 생각하지 못함  
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
struct Info{ int s; int w; };
Info egg[10];

void func(int k){
    if(k == n){
        int broken = 0;
        for(int i=0; i < n; ++i){
            if(egg[i].s <= 0) ++broken;
        }
        res = max(res, broken);
        return;
    }

    // 현재 계란이 이미 깨졌다면 바로 다음 계란 이동
    if(egg[k].s <= 0){
        func(k+1);
        return;
    }

    bool check = false;
    for(int i=0; i < n; ++i){
        // 손에 든 계란이거나, 이미 깨진 계란이면 패스
        if(i == k || egg[i].s <= 0) continue; 

        // 계란 칠 때,
        egg[k].s -= egg[i].w;
        egg[i].s -= egg[k].w;
        check = true;
        // 다음 계란 이동
        func(k+1);
        // 원상 복구
        egg[k].s += egg[i].w;
        egg[i].s += egg[k].w;
    }
    // 계란 모두 깨진 상황(현재 계란은 남아있고)
    if(!check)  func(k+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i){
        cin >> egg[i].s >> egg[i].w;
    }
    func(0);
    cout << res;
    return 0;
}
```

### 1941_소문난 칠공주
-> BFS + DFS 함께 섞인 문제
1. 백트래킹(DFS) 사용하여 25명 중 7명 뽑기 = 조합
2. 4명 이상 있는지 확인하는 함수
3. BFS 사용하여 7명 인접한지 확인

```cpp
// 1941 소문난 칠공주 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[5][5]; // Y, S 저장하는 보드 
int isused[25]; // 조합 -> 7명 뽑을 때 사용 여부 판단
int ans; 

struct Pos{int y; int x; };
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void input(){
    for(int i=0; i < 5; ++i){
        string str;
        cin >> str;
        for(int j=0; j < 5; ++j){
            if(str[j] == 'Y')   board[i][j] = 1;
            if(str[j] == 'S')   board[i][j] = 2;
        }
    }
}

// 4명 이상 있는지 확인
bool ismore4(){
    int Y_cnt=0, S_cnt=0;
    for(int i=0; i < 25; ++i){
        if(isused[i]){
            int y = i / 5;
            int x = i % 5;
            if(board[y][x] == 1)   Y_cnt++;
            if(board[y][x] == 2)   S_cnt++;
        }
    }
    return (S_cnt >= 4);
}

// 7명 서로 인접한지 확인(BFS)
bool adjency(){
    queue<Pos> q;
    int vis[5][5] = {0, }; // 방문 여부 저장
    
    // 7명 위치 좌표 저장
    vector<Pos> sel;
    for(int i=0; i < 25; ++i){
        if(isused[i]){
            sel.push_back({i/5, i%5});
        }
    }

    q.push(sel[0]);
    vis[sel[0].y][sel[0].x] = 1;

    int cnt = 1; // 연결된 요소 수 
    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)  continue;
            if(vis[ny][nx]) continue;

            // ny, nx가 현재 뽑힌 7명에 포함되는지 확인
            for(const Pos& p : sel){
                if(p.y == ny && p.x == nx && !vis[ny][nx]){
                    vis[ny][nx] = 1;
                    q.push({ny, nx});
                    ++cnt;
                }
            }

        }
    }
    return (cnt==7);
}


// 25명 중 7명 뽑기
void dfs(int idx, int k){
    if(k == 7){
        if(ismore4() && adjency()){
            ans++;
        }
        return;
    }

    for(int i=idx; i < 25; ++i){
        if(!isused[i]){
            isused[i] = 1;
            dfs(i, k+1);
            isused[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    dfs(0, 0);
    cout << ans;
    return 0;
}
```




