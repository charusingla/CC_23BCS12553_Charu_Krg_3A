#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> jobs(n, vector<int> (3));
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
        max_deadline = max(max_deadline, jobs[i][1]);
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({jobs[i][2], jobs[i][1]});
    }
    vector<int> res(max_deadline + 1, 0);
    int total = 0;
    int cnt = 0;
    while (!pq.empty()) {
        int profit = pq.top().first;
        int deadline = pq.top().second;
        pq.pop();
        for (int i = deadline; i > 0; i--) {
            if (res[i] == 0) {
                res[i] = profit;
                total += profit;
                cnt++;
                break;
            }
        }
    }
    cout << cnt << " " << total;
    return 0;
}