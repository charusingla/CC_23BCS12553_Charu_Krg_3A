#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(5);
    graph[4].push_back(5);
    graph[4].push_back(0);

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto& it : graph[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto& it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
        cout << node << " ";
    }
    return 0;
}