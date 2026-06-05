#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> inter(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> inter[i][0] >> inter[i][1];
    }

    if (inter.size() <= 1) {
        for (auto &v : inter) {
            cout << v[0] << " " << v[1] << endl;
        }
        return 0;
    }
    sort(inter.begin(), inter.end());
    vector<vector<int>> results;
    vector<int> newi = inter[0];

    for (int i = 1; i < n; i++) {
        if (inter[i][0] <= newi[1]) {
            newi[1] = max(newi[1], inter[i][1]);
        } else {
            results.push_back(newi);
            newi = inter[i];
        }
    }

    results.push_back(newi);
    return 0;
}