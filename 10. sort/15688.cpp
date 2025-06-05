#include <iostream>
#include <algorithm>
using namespace std;

#if 0
int n;
int arr[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i < n; ++i)    cin >> arr[i];
    sort(arr, arr+n);

    for(int i=0; i < n; ++i)    cout << arr[i] << '\n';
    return 0;
}
#endif

// counting sort
int freq[2000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i < n; ++i){
        int a;
        cin >> a;
        freq[a+1000000]++;
    }

    for(int i=0; i <= 2000000; ++i){
        while(freq[i]--){
            cout << i - 1000000 << '\n';
        }
    }

}