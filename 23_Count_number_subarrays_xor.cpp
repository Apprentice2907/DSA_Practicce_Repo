// my approach but brute force 
// Time:O(N2) Space:O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums={4,2,2,6,4};
    int k=6;
    int n=nums.size();

    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum^nums[j];
            if(sum==k) count++;
        }
    }
    cout<<count;
    return 0;
}








// Optimal solution
// TIme:O(N) Space:O(N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    unordered_map<int, int> freq;
        freq[0] = 1;

        int sum = 0;
        int count = 0;

        for (int num : nums) {
            sum =sum^num;
            int target = sum ^ k;

            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }
            freq[sum]++;
        }
        cout<<sum;
    return 0;
}
