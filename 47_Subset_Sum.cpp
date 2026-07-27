// Normal Recursive technique 

class Solution {
  public:

    void findsums(int idx,int currsum,vector<int>& nums,vector<int>& sums){
        if(idx==nums.size()){
            sums.push_back(currsum);
            return;
        }
        findsums(idx+1,currsum+nums[idx],nums,sums);
        findsums(idx+1,currsum,nums,sums);
    }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> sums;
        findsums(0,0,nums,sums);
        sort(sums.begin(),sums.end());
        return sums;
    }
};








// Bitmasking different unique technique(Little bit difficult to understand and code)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find all subset sums using bitmasking
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> sums;

        // Iterate through all possible bitmasks from 0 to 2^n - 1
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0; // store sum of current subset
            for (int i = 0; i < n; i++) {
                // If ith bit is set, include arr[i] in sum
                if (mask & (1 << i)) {
                    sum += arr[i];
                }
            }
            sums.push_back(sum);
        }

        // Sort sums to get increasing order
        sort(sums.begin(), sums.end());
        return sums;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {5, 2, 1};
    vector<int> result = sol.subsetSums(arr);

    // Print the subset sums
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
