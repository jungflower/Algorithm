#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[4000002];
vector<int> prime;

void PrimeNumberSieve()
{
    // 1. 배열 생성하여 초기화
    for (int i = 2; i <= n; ++i) {
        a[i] = i;
    }

    // 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지움
    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0)   continue;
        // 지워진 수가 아니라면, 그 배수부터 출발하여 가능한 모든 숫자 지우기
        for (int j = 2 * i; j <= n; j += i) {
            a[j] = 0;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (a[i] != 0)   prime.push_back(a[i]);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    PrimeNumberSieve();

    int st = 0, en = 0, ans = 0, sum = 0;
    int prime_cnt = prime.size();
    //for (int i = 0; i < prime_cnt; ++i)    cout << prime[i] << '\n';

    while (st < prime_cnt) {
        if (sum >= n) {
            sum -= prime[st++];
        }
        else {
            if (en == prime_cnt)  break;
            sum += prime[en++];
        }
        if (sum == n)    ans++;
    }

    cout << ans;

    return 0;
}