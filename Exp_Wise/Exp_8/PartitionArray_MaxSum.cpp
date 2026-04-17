#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int N = arr.size();

    int dp[N + 1];
    memset(dp, 0, sizeof(dp));
    
    for (int start = N - 1; start >= 0; start--) {
        int currMax = 0;
        int end = min(N, start + k);

        for (int i = start; i < end; i++) {
            currMax = max(currMax, arr[i]);
            dp[start] = max(dp[start], dp[i + 1] + currMax * (i - start + 1));
        }
    }
    return dp[0];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int res = maxSumAfterPartitioning(arr, k);
    cout << res << endl;
}