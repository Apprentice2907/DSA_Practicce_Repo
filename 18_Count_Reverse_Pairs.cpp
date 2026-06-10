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




// Optimal solution (get the solution but find difficulty while writing)
// TIme:O(2N*logN) space:O(N)


#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int>& a, int l, int m, int r) {
    int count = 0;

    // Count reverse pairs
    int j = m + 1;
    for (int i = l; i <= m; i++) {
        while (j <= r && a[i] > 2LL * a[j]) {
            j++;
        }
        count += j - (m + 1);
    }

    // Merge two sorted halves
    vector<int> temp;
    int left = l, right = m + 1;

    while (left <= m && right <= r) {
        if (a[left] <= a[right])
            temp.push_back(a[left++]);
        else
            temp.push_back(a[right++]);
    }

    while (left <= m) temp.push_back(a[left++]);
    while (right <= r) temp.push_back(a[right++]);

    for (int i = l; i <= r; i++) {
        a[i] = temp[i - l];
    }

    return count;
}

int mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return 0;

    int m = (l + r) / 2;

    int count = 0;
    count += mergeSort(a, l, m);
    count += mergeSort(a, m + 1, r);
    count += mergeAndCount(a, l, m, r);

    return count;
}

int main() {
    vector<int> a = {4, 1, 2, 3, 1};
    cout << mergeSort(a, 0, a.size() - 1);
    return 0;
}