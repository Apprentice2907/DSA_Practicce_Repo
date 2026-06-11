// Brute Force approach 
// time:O(N2) Space:O(1)


// Optimal Approach (only if array contains both -ve and +ve)
// Time :O(N) space:O(N)

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> nums={9, -3, 3, -1, 6, -5};

//     unordered_map<int,int> mp;
//     int maxi=0; 
//     int sum=0; 
//     int k=0;

//     for(int i=0;i<nums.size();i++){
//         sum =sum+nums[i];
//         if(sum==k){
//             maxi=i+1;
//         }
//         else{
//             if(mp.find(sum)!=mp.end()){
//                 maxi=max(maxi,i-mp[sum]);
//             }
//             else{
//                 mp[sum]=i;
//             }
//         }
//     }
//     cout<<maxi;
//     return 0;
// }





// Optimal Approach (only if array contains +ve & 0)
// Time :O(2N) space:O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={9,4,3,6,8,4};

    int l=0;
    int r=0;
    int sum=nums[0];
    int maxl=0;
    int n=nums.size();
    int k=7;

    while(r<n){
        while(l<=r && sum>k){
            sum=sum-nums[l];
            l++;
        }
        if(sum==k){
            maxl=max(maxl,r-l+1);
        }
        r++;
        if(r<n) sum=sum+nums[r];
    }
    cout<<maxl;
    return 0;
}
