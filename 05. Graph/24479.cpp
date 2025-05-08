#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r, order=1;
vector<int> adj[100002];
bool vis[100002];
vector<int> ans;

void dfs(int cur){
    vis[cur] = true;
    ans[cur] = order++;
    for(auto nxt : adj[cur]){
        if(!vis[nxt])    dfs(nxt);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    ans.resize(n+1, 0); // 1 ~ n까지 사용하므로 n+1 크기로 초기화
    for(int i=0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());

    dfs(r);
    
    for(int i=1; i <= n; ++i)
        cout << ans[i] << '\n';
    
    return 0;
}