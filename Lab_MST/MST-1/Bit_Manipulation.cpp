#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int num : nums) {
            sum += num >> i & 1;
            sum %= 3;
            ans |= sum << i;
        }
    }
    cout << ans;
    return 0;
}

// T.C. = O(n)
// S.C. = O(1)