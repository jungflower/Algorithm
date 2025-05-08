#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, v;
vector<int> adj[1002];

void bfs(){

}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;
    for(int i=0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();

    return 0;
}