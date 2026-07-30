#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void rec(int idx,int target,vector<int>& nums,vector<vector<int>>& ans,vector<int>& res){
                if(target==0){
                    ans.push_back(res);
                    return;
                }

            for(int i=idx;i<nums.size();i++){
                if(i>idx && nums[i]==nums[i-1]) continue;
                if(nums[i]>target) break;
                res.push_back(nums[i]);
                rec(i+1,target-nums[i],nums,ans,res);
                res.pop_back();
            }
            // Cant deal with duplicate pair 
            // if(idx==nums.size()){
            //     if(target==0) ans.push_back(res);
            //     return;
            // }
            // if(nums[idx]<=target){
            //     res.push_back(nums[idx]);
            //     rec(idx+1,target-nums[idx],nums,ans,res);
            //     res.pop_back();
            // }
            // rec(idx+1,target,nums,ans,res);
        }

        vector<vector<int>> comb(vector<int> candidates,int target){
            vector<vector<int>> ans;
            vector<int> res;
            sort(candidates.begin(),candidates.end());
            rec(0,target,candidates,ans,res);
            return ans;
        }

};


int main(){
    Solution obj;
    int target=8;
    vector<int> v {1,1,2,5,6,7,10};
    vector<vector<int>> ans=obj.comb(v,target);

    for(int i=0; i < ans.size(); i++){
        for(int j=0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}