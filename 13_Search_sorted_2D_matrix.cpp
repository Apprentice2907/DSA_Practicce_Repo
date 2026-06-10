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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search target in a 2D matrix using binary search over a virtual 1D array
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows
        int n = matrix.size();

        // Get the number of columns
        int m = matrix[0].size();

        // Set initial binary search range over the imaginary 1D array
        int low = 0, high = n * m - 1;

        // Perform binary search
        while (low <= high) {
            // Calculate the middle index of the virtual 1D array
            int mid = (low + high) / 2;

            // Convert mid index to corresponding 2D indices
            int row = mid / m;
            int col = mid % m;

            // Check if the target is found
            if (matrix[row][col] == target)
                return true;

            // If the target is greater, discard the left half
            else if (matrix[row][col] < target)
                low = mid + 1;

            // If the target is smaller, discard the right half
            else
                high = mid - 1;
        }

        // If not found, return false
        return false;
    }
};

// Driver code
int main() {
    // Define a 2D matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Create an object of the Solution class
    Solution obj;

    // Call the function and print result
    if (obj.searchMatrix(matrix, 8))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
