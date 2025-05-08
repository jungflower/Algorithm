#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, start;
vector<int> adj[1002];
bool vis[1002];

void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if(vis[nxt])    continue;
        dfs(nxt);
    }
    return;
}

void bfs(){
    //fill(vis, vis+10002, 0); // 초기화
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]){
            if(vis[nxt])    continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
    cout << '\n';
    return;
}


 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;
    for(int i=0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 정접별 인접 리스트 정렬
    for(int i=1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(start);
    cout << '\n';
    bfs();

    return 0;
}