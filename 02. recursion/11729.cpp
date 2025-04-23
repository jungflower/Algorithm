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