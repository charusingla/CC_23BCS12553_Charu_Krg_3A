#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);

    for (auto &f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<tuple<int, int, int>> q;
    q.push({src, 0, 0});

    while (!q.empty()) {
        auto [node, cost, stops] = q.front();
        q.pop();

        if (stops > k) continue;

        for (auto &it : adj[node]) {
            int neighbor = it.first;
            int price = it.second;
            int newCost = cost + price;

            if (newCost < dist[neighbor] && stops <= k) {
                dist[neighbor] = newCost;
                q.push({neighbor, newCost, stops + 1});
            }
        }
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main() {
    int n, m, src, dst, k;
    cin >> n >> m >> src >> dst >> k;

    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int res = findCheapestPrice(n, flights, src, dst, k);
    cout << res << "\n";

    return 0;
}