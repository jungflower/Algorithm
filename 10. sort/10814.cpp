#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct info {int age; string name;};
vector<info> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        int age; string s;
        cin >> age >> s;
        v.push_back({age, s});
    }
    stable_sort(v.begin(), v.end(), [](const info &a, const info &b){
        return a.age < b.age;
    });

    for(const info& Info : v){
        cout << Info.age << ' ' << Info.name << '\n';
    }
    return 0;
}