// Brute force and my approach 
// Time:O(N2)


#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> nums(N);
    for(int i=0;i<N;i++) cin>>nums[i];

    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i<j && (nums[i]>2*nums[j])){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}




// Optimal solution 
// TIme:O(2N*logN) space:O(N)



