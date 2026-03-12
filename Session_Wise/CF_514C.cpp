#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll P = 31;
const ll MOD = 1000000009;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> p_pow(600001);
    p_pow[0] = 1;
    for (int i = 1; i <= 600000; i++)
        p_pow[i] = (p_pow[i - 1] * P) % MOD;

    unordered_set<ll> st;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll h = 0;
        for (int j = 0; j < s.size(); j++)
            h = (h + (s[j] - 'a' + 1) * p_pow[j]) % MOD;
        st.insert(h);
    }

    while (m--) {
        string s;
        cin >> s;

        ll h = 0;
        for (int i = 0; i < s.size(); i++)
            h = (h + (s[i] - 'a' + 1) * p_pow[i]) % MOD;

        bool ok = false;

        for (int i = 0; i < s.size() && !ok; i++) {
            char original = s[i];

            for (char c : {'a','b','c'}) {
                if (c == original) continue;

                ll new_hash = (h - (original - 'a' + 1) * p_pow[i] % MOD + MOD) % MOD;
                new_hash = (new_hash + (c - 'a' + 1) * p_pow[i]) % MOD;

                if (st.count(new_hash)) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}