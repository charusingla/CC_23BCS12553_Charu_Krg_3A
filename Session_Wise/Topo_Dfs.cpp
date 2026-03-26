#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& vis, int i, vector<vector<int>>& graph, stack<int>& st) {
    vis[i] = 1;
    for (auto& it : graph[i]) {
        if (!vis[it]) {
            dfs(vis, it, graph, st);
        }
    }
    st.push(i);
}

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

    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(vis, i, graph, st);
        }
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}