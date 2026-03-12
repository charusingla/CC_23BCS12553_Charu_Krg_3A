#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string,int> goals;
    string team;

    for(int i = 0; i < n; i++) {
        cin >> team;
        goals[team]++;
    }

    string winner;
    int maxGoals = 0;

    for(auto x : goals) {
        if(x.second > maxGoals) {
            maxGoals = x.second;
            winner = x.first;
        }
    }

    cout << winner;

    return 0;
}