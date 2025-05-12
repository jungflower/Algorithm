#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, order=1, res=1;
vector<int> adj[100002];
bool vis[100002];
vector<int> ans, pos;

// pos에 따라 정렬(오름차순)
bool cmp(int a, int b){
    return pos[a] < pos[b];
}

void dfs(int cur){
    vis[cur] = true;

    // 방문 순서 안맞으면 바로 종료
    if(cur != ans[order]){
        res = 0;
        return;
    }
    order++;

    for(auto nxt : adj[cur]){
        if(!vis[nxt]){
            dfs(nxt);
            if(res == 0)    return;
        }   
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    ans.resize(n+1, 0);
    pos.resize(n+1, 0);

    for(int i=0; i < n-1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1; i <= n; ++i){
        cin >> ans[i];
        pos[ans[i]] = i; // ans[i]의 순서 저장
    }
    
    // 각 노드의 인접 노드들을 'ans'의 방문 순서에 맞춰 정렬 필요 
    // 즉, 지정된 노드 탐색 순서로 정렬이 필요 ,,,
    for(int i=1; i <= n; ++i){
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
    dfs(1);
    cout << res;
    return 0;
}