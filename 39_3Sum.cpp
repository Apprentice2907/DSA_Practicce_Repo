// Optimal solution using 2 sum logic 
// Time:O(nlogn+N2) and space:O(1)
// My code just dont know how to code the duplicates one 


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if(sum > 0)
                    right--;

                if(sum < 0)
                    left++;

                else {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate values
                    while(left < right && nums[left] == nums[left - 1])
                        left++;

                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return ans;
    }
};


