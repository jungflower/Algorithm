#include <iostream>
using namespace std;

int a[1000005], b[1000005], arr[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    for(int i=0; i < n; ++i)    cin >> a[i];
    for(int i=0; i < m; ++i)    cin >> b[i];
    
    int aidx = 0, bidx = 0;
    for(int i=0; i < n+m; ++i){
        if(bidx == m)   arr[i] = a[aidx++];
        else if(aidx == n)  arr[i] = b[bidx++];
        else if(a[aidx] <= b[bidx]) arr[i] = a[aidx++];
        else    arr[i] = b[bidx++]; // (a[aidx] > b[bidx])   
    }

    for(int i=0; i < n+m; ++i)  cout << arr[i] << ' ';

    return 0;
}