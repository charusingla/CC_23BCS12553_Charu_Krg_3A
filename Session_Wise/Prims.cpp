#include <bits/stdc++.h>
using namespace std;
struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a > b;
    }
};
int main() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
}