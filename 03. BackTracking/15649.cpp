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