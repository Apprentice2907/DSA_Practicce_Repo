// Otpimal solution 
// time:O(N) Space:O(1)


class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxl=0;
        int maxr=0;
        int total=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=maxl) maxl=height[l];
                else total=total+maxl-height[l];
                l++;
            }
            else{
                if(height[r]>=maxr) maxr=height[r];
                else total=total+maxr-height[r];
                r--;
            }
        }
        return total;
    }
};