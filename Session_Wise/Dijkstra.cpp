#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    vector<long long> dist(n + 1, 1e18);
    dist[1] = 0;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (d > dist[node]) continue;
        for (auto& it : graph[node]) {
            if (dist[node] + it.second < dist[it.first]) {
                dist[it.first] = dist[node] + it.second;
                parent[it.first] = node;
                pq.push({dist[it.first], it.first});
            }
        }
    }
    if (dist[n] == 1e18) {
        cout << -1;
        return 0;
    }
    int nd = n;
    vector<int> path;
    
    while (parent[nd] != nd) {
        path.push_back(nd);
        nd = parent[nd];
    }
    path.push_back(1);
    
    reverse(path.begin(), path.end());
    
    for (int x : path) {
        cout << x << " ";
    }
    return 0;
}