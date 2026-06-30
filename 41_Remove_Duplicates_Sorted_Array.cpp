// Classic approach using two pointer
// Time:O(N) Space:O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n == 0)
            return 0;

        int i = 0;

        for (int j = 1; j < n; j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};





// My approach as understood the question wrong 
// time:O(N) Space:O(1) but more optimal than the prev one in leetcode platform


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;

        int temp = nums[0];   // Last unique element
        int blank = -1;      // First duplicate position

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == temp)
            {
                if (blank == -1)
                    blank = i;   // Remember first duplicate position
            }
            else
            {
                temp = nums[i];

                if (blank != -1)
                {
                    nums[blank] = nums[i];
                    blank++;
                }
            }
        }

        return (blank == -1) ? n : blank;
        }
};