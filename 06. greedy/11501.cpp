#include <iostream>
#include <vector>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> price;
        price.resize(n + 1);
        for (int i = 0; i < n; ++i)  cin >> price[i];

        long long gain = 0;
        int max_price = 0;

        // 뒤에서부터 최대값 갱신
        for(int i = n-1; i >= 0; --i){
            if(price[i] > max_price){
                max_price = price[i];
            }
            else{
                gain += max_price - price[i];
            }
        }
        cout << gain << '\n';
    }
    return 0;
}