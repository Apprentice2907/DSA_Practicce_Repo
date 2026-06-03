// mY logiv and but some test cases are not passed

#include<bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int buy=arr[0];
    int sell=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            continue;
        }
        if(arr[i]<buy){
            buy=arr[i];
            sell=0;
        }
        if(sell<arr[i]){
            sell=arr[i];
        }
    }
    cout<<sell-buy;
    return 0;
}




// Optimal and correct code while handling the edge case
// Time complexity: O(n) space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int buy = arr[0];
    int maxProfit = 0;

    for(int i = 1; i < N; i++) {
        if(arr[i] < buy) {
            buy = arr[i];
        }
        int profit = arr[i] - buy;
        maxProfit = max(maxProfit, profit);
    }
    cout << maxProfit;

    return 0;
}