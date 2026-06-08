// My approach using hashmapping 
// Time:O(N) space:O(N)

// Why unordered_map is generally preferred?
// Consider:
// nums = [1000000000, 1000000000, 2, 3]
// To use a vector, you'd need:
// vector<int> freq(1000000001);
// which is impossible/practicality terrible.
// An unordered_map only stores the elements that actually appear:
// {
//   1000000000 : 2,
//   2 : 1,
//   3 : 1
// }
// So its space is proportional to the number of distinct elements.


#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++) cin>>arr[i];

    unordered_map<int,int> freq;
    int n=arr.size();
    for(int num:arr){
        freq[num]++;
        if(freq[num]>n/2){
            cout<<num;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}






// Optimal solution 
// Space:O(1) time:O(N)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i];

    int ele = 0;
    int count = 0;
    for(int num : nums){
        if(count == 0)
            ele = num;
        if(num == ele)
            count++;
        else
            count--;
    }
    cout << ele;
    return 0;
}