// My approach and better logic
// Time:O(N logN) space:(1)

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    sort(nums.begin(), nums.end());

    int curr = 1;
    int maxi = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) {
            continue;
        }
        else if(nums[i] == nums[i-1] + 1) {
            curr++;
        }
        else {
            curr = 1;
        }
        maxi = max(maxi, curr);
    }
    cout << maxi;
    return 0;
}








// Optimal solution
// Time:O(N) space:O(N)

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    unordered_set<int> st(nums.begin(),nums.end());

    int l=0;
    for(int num:nums){
        if(st.find(num-1)==st.end()){
            int curr=num;
            int currl=1;
            while(st.find(curr+1)!=st.end()){
                curr++;
                currl++;
            }
            l=max(l,currl);
        }
    }
    cout<<l;

    return 0;
}