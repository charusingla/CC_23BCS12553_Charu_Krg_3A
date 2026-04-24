#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // Step 1: Coordinate Compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        // Step 2: Fenwick Tree (BIT)
        vector<int> BIT(sorted.size() + 1, 0);

        // Get compressed index
        auto getIndex = [&](int x) {
            return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
        };

        // Update BIT
        auto update = [&](int i) {
            while (i < BIT.size()) {
                BIT[i] += 1;
                i += i & -i;
            }
        };

        // Query BIT (prefix sum)
        auto query = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += BIT[i];
                i -= i & -i;
            }
            return sum;
        };

        // Step 3: Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int idx = getIndex(nums[i]);
            result[i] = query(idx - 1); // count of smaller elements
            update(idx);
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> ans = obj.countSmaller(nums);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}