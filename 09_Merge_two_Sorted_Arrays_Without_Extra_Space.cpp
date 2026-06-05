// Simple approach 
// Time complexity:O(nlogn+m) space complexity:O(n+m)

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> nums1(n+m);
//     vector<int> nums2(m);
//     for(int i=0;i<n+m;i++){
//         cin>>nums1[i];
//     }
//     for(int i=0;i<m;i++){
//         cin>>nums2[i];
//     }
//     int j=0;
//     for(int i=0;i<n+m;i++){
//         if(nums1[i]==0){
//             swap(nums1[i],nums2[j]);
//             j=j+1;
//         }
//     }
//     sort(nums1.begin(),nums1.end());
//     for(int i=0;i<n+m;i++){
//         cout<<nums1[i]<<" ";
//     }
//     return 0;

// }



// Optimal approach 
// TIme complexity: O(m+n) space complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n+m);
    vector<int> nums2(m);
    for(int i=0;i<n+m;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    int i=n-1;
    int k=n+m-1;
    int j=m-1;
    while(i>=0 && j>=0){
        if(nums1[i]<nums2[j]){
            nums1[k]=nums2[j];
            j=j-1;
            k=k-1;
        }
        else{
            nums1[k]=nums1[i];
            i=i-1;
            k=k-1;
        }
    
    }
    while(j>=0){ //nums1 = [5, 6, 7, 0, 0, 0], nums2 = [1, 2, 3]
        nums1[k] = nums2[j];
        j=j-1;
        k=k-1;
    }
    for(int x : nums1) {
        cout << x << " ";
    }
    return 0;

}