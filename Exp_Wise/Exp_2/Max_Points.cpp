#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    if (n <= 2) {
        cout << n;
        return 0;
    }

    int ans = 1;

    for (int i = 0; i < n; i++) {
        map<pair<int,int>, int> mp;
        int duplicate = 0;
        int localMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;

            if (dx == 0 && dy == 0) {
                duplicate++;
                continue;
            }

            int g = gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            else if (dx == 0) {
                dy = 1;
            }
            else if (dy == 0) {
                dx = 1;
            }

            mp[{dy, dx}]++;
            localMax = max(localMax, mp[{dy, dx}]);
        }

        ans = max(ans, localMax + duplicate + 1);
    }

    cout << ans;
    return 0;
}