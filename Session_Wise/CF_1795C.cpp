#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n+1), b(n+1), pref(n+1), diff(n+2), extra(n+2);

        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++){
            cin >> b[i];
            pref[i] = pref[i-1] + b[i];
        }

        for(int i=1;i<=n;i++){
            long long need = a[i] + pref[i-1];
            int pos = upper_bound(pref.begin()+1, pref.begin()+n+1, need) - pref.begin();

            diff[i]++;
            diff[pos]--;

            if(pos <= n)
                extra[pos] += need - pref[pos-1];
        }

        long long cur = 0;

        for(int i=1;i<=n;i++){
            cur += diff[i];
            long long ans = cur * b[i] + extra[i];
            cout << ans << " ";
        }

        cout << "\n";
    }
}