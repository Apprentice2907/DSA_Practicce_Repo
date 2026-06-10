// Most optimal solution using maths
// Time:O(min(M,N)) space:(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int N = m + n - 2;
    int r = min(m - 1, n - 1);

    long long ans = 1;

    for (int i = 1; i <= r; i++) {
        ans = ans * (N - r + i) / i;
    }

    cout << ans;

    return 0;
}



// Most common Memoization approach
// Time:O(M*N) space:O(M*N)

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& dp) {
    
    if(i == 0 && j == 0) return 1;
    
    if(i < 0 || j < 0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = solve(i-1, j, dp) + solve(i, j-1, dp);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m-1, n-1, dp);
}

int main() {
    int m = 3, n = 2;
    cout << uniquePaths(m, n);
}




// Tabulation method
// Time:O(M*N) space:O(M*N)

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(i == 0 && j == 0)
                dp[i][j] = 1;
            else {
                int up = (i > 0) ? dp[i-1][j] : 0;
                int left = (j > 0) ? dp[i][j-1] : 0;

                dp[i][j] = up + left;
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
    cout << uniquePaths(3, 2);
}








// Optimal solution space optimized
// Time:O(M*N) Space:O(N)


#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {

    vector<int> prev(n, 0);

    for(int i = 0; i < m; i++) {

        vector<int> curr(n, 0);

        for(int j = 0; j < n; j++) {

            if(i == 0 && j == 0) {
                curr[j] = 1;
            }
            else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;

                curr[j] = up + left;
            }
        }

        prev = curr;
    }

    return prev[n - 1];
}

int main() {
    cout << uniquePaths(3, 2);
}