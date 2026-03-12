#include <bits/stdc++.h>
using namespace std;
const int base = 256;

int hashFunc(string str) {
    int result = 0;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        result = result * base + (str[i] - 'a' + 1);
    }
    return result;
}

int main() {
    string txt;
    cin >> txt;
    string patt;
    cin >> patt;
    int n = txt.size();
    int m = patt.size();
    int txtHash = hashFunc(txt.substr(0, m));
    int pattHash = hashFunc(patt);
    int power = 1;
    for (int i = 0; i < m - 1; i++) {
        power = power * base;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (txtHash == pattHash) {
            cout << "String is found at index " << i << endl;
        }
        if (i < n - m) {
            txtHash -= (txt[i] - 'a' + 1) * power;
            txtHash = txtHash * base;
            txtHash += (txt[i + m] - 'a' + 1);
        }
    }
    return 0;
}
