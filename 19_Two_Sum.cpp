// Brute Force method
// Time:O(N2) space:(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int target;
    cin>>target;

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}






// My approach optimal solution
// Sort and then two pointer
// Time: O(N logN) space:O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int target;
    cin>>target;

    sort(arr.begin(),arr.end());

    int i=0;
    int j=arr.size()-1;

    while(i<j){
        if(arr[i]+arr[j]>target) j--;
        else if(arr[i]+arr[j]<target) i++;
        else{
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}






// Time optimal solution(Not my approach id didnt get this)
// Time:O(N) space:O(N)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int target;
    cin>>target;

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int sum=target-arr[i];
        if(mp.find(sum)!=mp.end()){
            cout<<"YES";
            return 0;
        }
        mp[arr[i]]=i;
    }
    cout<<"NO"
    return 0;
}