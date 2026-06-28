class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector<int> bits;
        while(n>0){
            bits.push_back(n&1);
            n=n>>1;
        }
        reverse(bits.begin(),bits.end());
        int count=0;
        for(int i=1;i<bits.size();i++){
            if(bits[i]==1 && bits[i-1]==1){
                count=count+1;
            }
        }
        if(count==1) return true;
        return false;
    }
};







class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sq=0;
        while(n>0){
            int digit=n%10;
            sum=sum+digit;
            sq=sq+(digit*digit);
            n=n/10;
        }
        if(sq-sum>=50) return true;
        return false;
    }
}











class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long sum=0;
        int mini=INT_MAX;
        int smin=INT_MAX;
        if(units[0].size()==1){
            long long ans=0;
            for(int i=0;i<units.size();i++){
                ans=ans+units[i][0];
            }
            return ans;
        }
        
        for(int i=0;i<units.size();i++){
            sort(units[i].begin(),units[i].end());
            mini=min(mini,units[i][0]);
            sum=sum+units[i][1];
            smin=min(smin,units[i][1]);
        }
        return sum+mini-smin;
    }
}








class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(), greater<int>());
        long long ans=0;
        long long curr=mul;
        for(int i=0;i<k;i++){
            if(curr>1) ans=ans+(long long)nums[i]*curr;
            else ans=ans+nums[i];
            curr=curr-1;
        }
        return ans;
    }
};©leetcode