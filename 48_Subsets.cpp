// Optimal solution
// time:O(2^N) Space:O(N)

class Solution {
public:
    void back(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            back(i+1,nums,curr,ans);
            curr.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        back(0,nums,curr,ans);
        return ans;
    }
};






// Brute Force
// Time:O(N² * 2^N) Space:O(N * 2^N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive helper to generate all subsets
    void findSubsets(int ind, vector<int>& nums, vector<int>& ds, set<vector<int>>& result) {
        // Base case: if we've considered all elements, add the current subset to the result set
        if (ind == nums.size()) {
            result.insert(ds);
            return;
        }

        // Choice 1: Include the element at the current index
        ds.push_back(nums[ind]);
        findSubsets(ind + 1, nums, ds, result);
        // Backtrack to explore the other choice
        ds.pop_back();

        // Choice 2: Do not include the element at the current index
        findSubsets(ind + 1, nums, ds, result);
    }

    // Main function to find all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> ds;
        // Sort the array to handle duplicates consistently
        sort(nums.begin(), nums.end());
        
        findSubsets(0, nums, ds, result);

        // Convert the set of unique subsets to a vector for the final answer
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};

// Driver code to test the solution
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = sol.subsetsWithDup(nums);
    
    // Print the result
    cout << "[ ";
    for (const auto& subset : ans) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;

    return 0;
}