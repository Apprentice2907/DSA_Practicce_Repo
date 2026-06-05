// My logic using hashmapping and time complexity: O(n) and space:O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=0;i<n+1;i++){
        cin>>arr[i];
    }

    vector<int> freq(n+1,0);
    for(int num:arr){
        if(freq[num]==1){
            cout<<num;
        }
        freq[num]++;
    }
    return 0;
}


// Optimal solution time complexity: O(n) space :O(1)
// Floyd cycle detection (tortoise and hare)
// slow and fast pointer logic 

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=0;i<n+1;i++){
        cin>>nums[i];
    }

    int slow=0;
    int fast=0;
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    } while( slow!=fast);

    slow=0;
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    cout<<slow;
    return 0;
}