// My logic and correct but lengthy
// Time complexity:O(N)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int sum = arr[0];
    int maxs = arr[0];

    for(int i = 1; i < N; i++){
        if(sum + arr[i] > arr[i]){
            sum = sum + arr[i];
        }
        else{
            sum = arr[i];
        }
        if(sum > maxs){
            maxs = sum;
        }
    }
    cout << maxs;
    return 0;
}




// Kadane's algorithm

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int maxs=arr[0];
    int sum=arr[0];

    for(int i=1;i<arr.size();i++){
        sum=max(arr[i],sum+arr[i]);
        maxs=max(maxs,sum);
    }
    cout<<maxs;

    return 0;
}