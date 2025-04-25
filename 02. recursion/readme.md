# 재귀

재귀는 자신이 수행할 작업을 유사한 형태의 여러 조각으로 쪼갠 뒤, 그 중 한 조각을 수행하고, 나머지를 자기 자신을 호출하여 실행하는 함수

=> **수학적 귀납법**으로 사고하는 것이 중요!

수학적 귀납법
1번 도미노가 쓰러진다.
k번 도미노가 쓰러지면 k+1 도미노도 쓰러진다.

```cpp
void func1(int n){
    if(n == 0) return;
    cout << n << ' ';
    func1(n-1);
}
```
func1(1)이 1을 출력한다.
func1(k)가 k k-1 k-2 ... 1을 출력한다.
func1(k+1)은 k+1 k k-1 k-2 ... 1을 출력한다.

### 재귀함수의 조건 ###
특정 입력에 대해서는 자기 자신을 호출하지 않고 종료되어야함(Base Condition)
모든 입력은 base condition으로 수렴해야함!

### 재귀에 대한 정보 ###
1. 함수의 인자로 어떤 것을 받고 어디까지 계산 한 후, 자기자신에게 넘겨줄지 명확하게 해야함 -> 모든 재귀 함수는 반복문만으로 동일한 동작을 하는 함수를 만들 수 있음 
=> 재귀는 반복문으로 구현했을 때에 비해 코드가 간결하지만 메모리/시간에서는 손해를 봄

2. 한 함수가 자기 자신을 여러 번 호출하게 되면 비효율적일 수 있음
```cpp
int fibo(int n){
    if(n <= 1)  return 1;
    return fibo(n-1) + fibo(n-2);
}
```
-> 시간복잡도 O(2ⁿ) 

3. 재귀함수가 자기 자신을 부를 때 스택 영역에 계속 누적이 됨

## 알고리즘 순서 ##
->아래와 같은 step으로 재귀를 작성

1. 함수의 정의
2. base condition 
3. 재귀 식

## 예제 ##
### 1629_곱셈 (거듭제곱)
https://www.acmicpc.net/problem/1629 

$a^b \mod b$ 
-> 시간 제한 0.5s로 그냥 반복돌려서 곱셈하는 것은 안됨,, O(n)말고!

ex) $12^{116} \mod 67$   
$a^n * a^n = a^{2n}$  
$12^{58} = 4 (mod 67) -> 12^{116} = 16(mod 67)$ 

-> 1승을 계산할 수 있다.
-> k승을 계산했으면 2k승과 2k+1승도 O(1)에 계산할 수 있다

```cpp
#include <iostream>
#include <cmath>
using namespace std;

long long a, b, c;
int pow(int a, int b, int c){
    // 기저 상태
    if(b == 1)    return a % c;
    // 재귀적으로, a^(b/2)mod b 계산해 val에 대입
    long long val = pow(a, b/2, c);
    // val 제곱에 나머지 = 우리가 구하고자 하는 나머지
    val = val * val % c;
    if(b % 2 == 0)  return val;// 짝수
    return val * a % c; // 홀수-> a한번 더 곱한 나머지로 구해야 함
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    cout << pow(a, b, c);
    return 0;
}
```

### 11729_하노이 탑 이동순서 (하노이탑)
https://www.acmicpc.net/problem/11729

n-1개의 원판을 기둥 1에서 기둥 2로 옮긴다.
n번 원판을 기둥1에서 기둥 3으로 옮긴다.
n-1개의 원판을 기둥2에서 기둥3으로 옮긴다  
-> 원판이 n-1개일 때 옮길 수 있으면 원판이 n개일때도 옮길 수 있다!  

원판이 1개일 때 원판을 내가 원하는 곳으로 옮길 수 있다.  
원판이 k개일 때 옮길 수 있으면 원판이 k+1일때에도 옮길 수 있다.

1. 함수의 정의  
    void func(int a, int b, int n)  
    원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수  

2. base condition  
n=1일때, `cout << a << ' ' << b << '\n;`

3. 재귀식  
    1. n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.  
    `func(a, 6-a-b, n-1);` // 번호의 합이 6이라, 6-a-b

    2. n번 원판을 기둥 a에서 기둥 b로 옮긴다.  
    `cout << a << ' ' << b << '\n;`

    3. n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.    
    `func(6-a-b, b, n-1);`    

* 옮긴 횟수: 원판 K개를 옮기기 위해 A번이 필요하다면, k+1개를 옮길 때는 k개의 원판을 빈 곳으로 옮길 때 A번, k+1번 원판을 옮길 때 1번, k개의 원판을 다시 빈곳에서 목적지로 옮길 때 A번이 필요하니 2A+1번 이동이 필요
-> 즉,, 초항이 1이라 이 수열의 일반항은 $2^k-1$이 된다.

```cpp
#include <iostream>
using namespace std;

void func(int a, int b, int n){
    if(n == 1) {
        cout << a << ' ' << b << '\n';
        return ;
    }
    func(a, 6-a-b, n-1); // n-1개의 원판을 a번(출발지)에서 6-a-b로 이동(6은 기둥 번호 1+2+3=6)
    cout << a << ' ' << b << '\n'; // n번째 원판 기둥 a에서 b로 이동
    func(6-a-b, b, n-1); // n-1개의 원판을 6-a-b번에서 b번으로 이동동

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    cout << (1<<k) - 1 << '\n'; // 옮긴 횟수
    func(1, 3, k);

    return 0;



}
```

### 1074_Z
1. 함수의 정의  
    `int func(int n, int r, int c)`  
    $2^n * 2^n$배열에서 (r,c) 를 방문하는 순서를 반환하는 함수  

2. base condition  
    n = 0일때, `return 0;`  

3. 재귀식  
    (r, c)가 1번 사각형일 때, `return func(n-1, r, c);`  
    (r,c)가 2번 사각형일 때, `return half*half + func(n-1, r, c-h);`  
    (r,c)가 3번 사각형일 때, `return 2*half *half + func(n-1, r-half, c);`  
    (r,c)가 4번 사각형일 때, `return 3*half *half + func(n-1, r-half, c-half);`  
    -> half는 한 변 길이의 절반
 ```cpp
 #include <iostream>
using namespace std;

int func(int n, int r, int c){
    if(n==0)    return 0;
    int half = 1 << (n-1); // 한 변 길이의 절반
    if(r < half && c < half)    return func(n-1, r, c);
    if(r < half && c >= half)    return half*half + func(n-1, r, c-half);
    if(r >= half && c < half)    return 2*half*half + func(n-1, r-half, c);
    if(r >= half && c >= half)   return 3*half*half + func(n-1, r-half, c-half);
}

int main(){
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
    return 0;
}
 ```

### 17458_재귀함수가 뭔가요?
```cpp
#include <iostream>
using namespace std;


void recursion(int n, string str){

    cout << str << "\"재귀함수가 뭔가요?\"\n";
    if(n==0){
        cout << str << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cout << str << "라고 답변하였지.\n";
        return;
    }
    cout << str << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    cout << str << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    cout << str << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    recursion(n-1, str + "____");
    cout << str << "라고 답변하였지.\n";
    return ;
}

int main()
{
    int n;
    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    recursion(n, "");
    return 0;
}
```

**알고리즘 설계**
1. 함수의 정의
    void recursion(int n, string str);
    각 문장을 n개만큼 str = _ _ _ _ 만큼 추가하여 출력하는 함수

2. base condition
    n = 0일 때, 마지막에만 출력하는 문장 출력력

3. 재귀 식
    n, n-1, n-2 ... 0까지 _ _ _ _ 를 x2배씩 앞에 늘려가며 출력하는 함수

### 1780_종이의 개수  
-> NxN 크기의 종이를 9등분해서 모두 같은 수로만 채워진 종이인지 판단해야 함
-> 같은 수가 아니면 다시 9등분 → 재귀적 접근 필요

```cpp
// 1780 종이의 개수
// 내가 못품...
#include <iostream>
using namespace std;

int n;
int paper[2200][2200];
int cnt[3]; // -1 0 1 수

// 해당 종이 내부에 같은 숫자로만 채워져있는지 확인하는 함수
bool check(int y, int x, int z){
    for(int i=y; i < y+z; ++i){
        for(int j=x; j < x+z; ++j){
            if(paper[y][x] != paper[i][j])
                return false;
        }
    }
    return true;
}

void solve(int y, int x, int z){
    // 같은 숫자로만 채워져있으면 cnt 추가
    if(check(y, x, z)){
        cnt[paper[y][x] + 1]++;
        return;
    }
    int N = z / 3;
    // 9등분으로 나눠서 다시 재귀 탐색 
    for(int i=0; i < 3 ; ++i){
        for(int j=0; j < 3; ++j){
            solve(y + i*N, x + j*N, N);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int y=0; y < n; ++y)
        for(int x=0; x < n; ++x)
            cin >> paper[y][x];
    
    solve(0, 0, n);
    for(int i=0; i < 3 ;i++)    cout << cnt[i] << '\n';
    return 0;
}
```  
**알고리즘 설계**
1. 함수의 정의  
`bool check(int y, int x, int z)`  
(y, x)부터 z x z 크기의 종이가 모두 같은 숫자인지 확인하는 함수  
`void solve(int y, int x, int z)`  
(y,x)부터 z x z종이를 같은 숫자라면 cnt++ / 아니라면 9등분해서 재귀 호출

2. base conditon  
```cpp
    if(check(y, x, z)){
        cnt[paper[y][x] + 1]++;
        return;
    }
```
-> 현재 영역이 모두 같은 숫자라면 반환

3. 재귀 식  
9등분으로 나누어서 재귀 탐색 시작
```cpp
    for(int i=0; i < 3 ; ++i){
        for(int j=0; j < 3; ++j){
            solve(y + i*N, x + j*N, N);
        }
    }
```
### 1992_쿼드트리 ###   
```cpp
// 1992 쿼드트리
#include <iostream>
using namespace std;

int N;
string quad[64];

// 현재 (y, x) 위치에서 n x n 크기의 영역이 모두 같은 숫자인지 확인하는 함수
bool check(int y, int x, int n){
    for(int i=y; i < y+n; ++i){
        for(int j=x; j < x+n; ++j){
            if(quad[y][x] != quad[i][j])
                return false;
        }
    }
    return true;
}

void solve(int y, int x, int n){
    if(check(y, x, n)){ // 모든 숫자 같으면 해당 숫자 출력
        cout << quad[y][x];
        return;
    }

    // 모두 같은 수가 아니라면, 
    // n/2 * n/2으로 영역 4등분 하여 재귀 
    cout << "(";
    solve(y, x, n/2); // 왼쪽 위
    solve(y, x+n/2, n/2); // 오른쪽 위
    solve(y+n/2, x, n/2); // 왼쪽 아래
    solve(y+n/2, x+n/2, n/2); // 오른쪽 아래
    cout << ")";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; ++i){
        cin >> quad[i];
    }
    solve(0, 0, N);
    
    return 0;
}
```
1. 함수의 정의
```cpp
void solve(int y, int x, int n);
```
(y,x)를 좌측 상단부터 시작해서 크기가 nxn인 정사각형 영역에 대해 쿼트 트리 문자열 출력하는 함수

2. base condition
```cpp
if (check(y, x, n)) {
    cout << quad[y][x];
    return;
}
```
현재 영역의 모든 값이 동일하면 더 이상 쪼갤 필요가 없으므로, 그 숫자(0 or 1)만 출력하고 재귀 종료

3. 재귀 식
```cpp
    cout << "(";
    solve(y, x, n/2);             // 왼쪽 위
    solve(y, x + n/2, n/2);       // 오른쪽 위
    solve(y + n/2, x, n/2);       // 왼쪽 아래
    solve(y + n/2, x + n/2, n/2); // 오른쪽 아래
    cout << ")";
```
같은 숫자아니면 4등분해서, 각 영역 순서대로 재귀 호출

### 2630_색종이 만들기
```cpp
// 2630 색종이 만들기 
#include <iostream>
using namespace std;

int N;
int paper[128][128];
int cnt[2] = {0, }; // 0 -> 하얀색, 1 -> 파란색

// n X n 내에서 (y, x)부터 같은지 판단하는 함수
bool check(int y, int x, int n){
    for(int i=y; i < y+n; ++i){
        for(int j=x; j < x+n; ++j){
            if(paper[i][j] != paper[y][x])  return false;
        }
    }
    return true;
}

void solve(int y, int x, int n){
    if(check(y, x, n)){
        ++cnt[paper[y][x]];
        return ;
    }

    solve(y, x, n/2);
    solve(y, x+n/2, n/2);
    solve(y+n/2, x, n/2);
    solve(y+n/2, x+n/2, n/2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i < N; ++i){
        for(int j=0; j < N; ++j){
            cin >> paper[i][j];
        }
    }
    solve(0, 0, N);
    for(int i=0; i < 2; ++i)    cout << cnt[i] << '\n';
    return 0;
}
```


 


