// My approach as GPT helped me to understand the lexicographical pattern ,whats that and pattern
// time complexity: O(N)+O(N)+O(N)=O(N) and time complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int temp=-1;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int N=arr.size();

    for(int i=N-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            temp=i;
            break;
        }
    }

    if(temp == -1){
        reverse(arr.begin(), arr.end());

        for(int x : arr){
            cout << x << " ";
        }
        return 0;
    }

    for(int j=N-1;j>temp;j--){
        if(arr[j]>arr[temp]){
            swap(arr[temp],arr[j]);
            break;
        }
    }

    reverse(arr.begin() + temp + 1, arr.end());  //Help
    
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}