// My approach better approach 
// time complexity :O(m + n) space:O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    for(int i = 0; i < m; i++) {
        if(matrix[i][0] <= target && matrix[i][n - 1] >= target) {
            for(int num : matrix[i]) {
                if(num == target) {
                    cout << true;
                    return 0;
                }
            }
        }
    }
    cout << false;
    return 0;
}




// Optimal solution using binary search
// Time :O(log(m*n)) space:O(1)

