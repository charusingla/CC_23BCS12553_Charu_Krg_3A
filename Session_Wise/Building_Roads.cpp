#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
bool vis[200005];

void dfs(int node){
    vis[node] = true;
    for(int next : adj[node]){
        if(!vis[next])
            dfs(next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> comp;

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            comp.push_back(i);
            dfs(i);
        }
    }

    cout << comp.size() - 1 << "\n";

    for(int i = 1; i < comp.size(); i++){
        cout << comp[i-1] << " " << comp[i] << "\n";
    }

    return 0;
}