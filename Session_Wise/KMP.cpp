#include<bits/stdc++.h>
using namespace std;

int main(){

    string pattern = "cba";
    string s = "abcabcbadbbcba";
    int m = pattern.size();
    int n = s.size();

    
    vector<int> lps(m,0);

    
    int length = 0; 
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    
    i = 0; 
    int j = 0; 
    while (i < n) {
        if (pattern[j] == s[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1]; 
        } else if (i < n && pattern[j] != s[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}