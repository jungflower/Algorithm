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