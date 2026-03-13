#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> tokens(n);
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }
    int power;
    cin >> power;
    sort(tokens.begin(), tokens.end());
    
    int maxScore = 0;      
    int currScore = 0;  
    
    int left = 0;
    int right = tokens.size() - 1;
    
    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left];
            left++;
            currScore++;
            maxScore = max(maxScore, currScore);
        }
        else if (currScore > 0) {
            power += tokens[right];
            right--;
            currScore--;
        }
        else {
            break;
        }
    }
    cout << maxScore;
    return 0;
}

// T.C. = O(n log n)
// S.C. = O(log n)
