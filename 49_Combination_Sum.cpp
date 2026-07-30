// Didnt get the logic while dealing with it so have to watch solution and get it afterwards

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void rec(int idx,int t,vector<int>& arr,vector<vector<int>>& ans,vector<int>& store){
            if(idx==arr.size()){
                if(t==0) ans.push_back(store);
                return;
            }
            if(arr[idx]<=t){
                store.push_back(arr[idx]);
                rec(idx,t-arr[idx],arr,ans,store);
                store.pop_back();
            }
            rec(idx+1,t,arr,ans,store);
        }
    public:
        vector<vector<int>> comb(vector<int>& candidates,int target){
            vector<vector<int>> ans;
            vector<int> store;
            rec(0,target,candidates,ans,store);
            return ans;
        }
};

int main(){
    Solution obj;
    int target=7;
    vector<int> v {2,3,6,7};
    vector<vector<int>> ans=obj.comb(v,target);

    for(int i=0; i < ans.size(); i++){
        for(int j=0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}