#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    string s;
    cin >> k >> s;

    unordered_map<long long,long long> freq;
    freq[0] = 1;

    long long pref = 0, ans = 0;

    for(char c : s){
        if(c == '1') pref++;

        if(freq.count(pref - k))
            ans += freq[pref - k];

        freq[pref]++;
    }

    cout << ans;
}