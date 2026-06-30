// Optimal and simple solution and easy question  
// Time:O(N) Space:O(1)


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                maxc=max(maxc,count);
            }
            if(nums[i]!=1){
                count=0;
            }
        }
        return maxc;
    }
};