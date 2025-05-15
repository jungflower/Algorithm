#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int A[52], B[52];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i){
        cin >> A[i];
    }
    for(int i=0; i < n; ++i){
        cin >> B[i];
    }
    sort(A, A+n);
    sort(B, B+n);

    int s = 0;
    for(int i=0; i < n; ++i){
        s += A[i] * B[n-i-1]; 
    }
    cout << s;
    return 0;
}