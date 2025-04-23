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
