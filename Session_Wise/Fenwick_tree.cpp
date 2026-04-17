#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    int queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5}; 
    int n = arr.size() - 1;
    
    FenwickTree ft(n);
    for (int i = 1; i <= n; i++) {
        ft.update(i, arr[i]);
    }

    cout << "Sum of range [1, 3]: " << ft.queryRange(1, 3) << endl; 
    ft.update(2, 5); 
    cout << "Sum of range [1, 3] after update: " << ft.queryRange(1, 3) << endl; 

    return 0;
}
