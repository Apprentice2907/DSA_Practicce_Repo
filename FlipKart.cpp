// Question-2

#include <bits/stdc++.h>
using namespace std;

int turningPointSum(vector<int>& val, vector<string>& path) {
    unordered_map<string, int> mp;

    for (int i = 0; i < path.size(); i++)
        mp[path[i]] = val[i];

    int ans = 0;

    for (int i = 0; i < path.size(); i++) {
        if (mp.count(path[i] + "L") && mp.count(path[i] + "R"))
            ans += val[i];
    }

    return ans;
}

int main() {
    // Static Input
    vector<int> val = {56, 65, 75, 78, 79, 89, 90, 100};
    vector<string> path = {
        "",        // Root
        "L",       // Left of Root
        "LR",      // Right of L
        "LRL",     // Left of LR
        "LRLL",    // Left of LRL
        "LRLR",    // Right of LRL
        "LRLRL",   // Left of LRLR
        "LRLRR"    // Right of LRLR
    };

    cout << "Values: ";
    for (int x : val)
        cout << x << " ";

    cout << "\n\nPaths:\n";
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == "")
            cout << "Root";
        else
            cout << path[i];

        cout << " -> " << val[i] << endl;
    }

    cout << "\nTurning Point Sum = " << turningPointSum(val, path) << endl;

    return 0;
}