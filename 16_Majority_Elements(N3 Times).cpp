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
// Little bit GPT 


#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for(int num : arr) {
        freq[num]++;
    }

    vector<int> ans;
    for(auto it : freq) {
        if(it.second > N / 3) {
            ans.push_back(it.first);
        }
    }
    for(int num : ans) {
        cout << num << " ";
    }
    return 0;
}






// Optimal solution GPT and striver 
// Time:O(N) space:O(1)


#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for(int i = 0; i < N; i++) cin >> nums[i];

    int ele1 = 0, ele2 = 0;
    int count1 = 0, count2 = 0;

    for(int num : nums) {
        if(num == ele1) {
            count1++;
        }
        else if(num == ele2) {
            count2++;
        }
        else if(count1 == 0) {
            ele1 = num;
            count1 = 1;
        }
        else if(count2 == 0) {
            ele2 = num;
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }

    // Verification pass
    count1 = 0;
    count2 = 0;

    for(int num : nums) {
        if(num == ele1) count1++;
        else if(num == ele2) count2++;
    }

    vector<int> ans;

    if(count1 > N / 3) ans.push_back(ele1);
    if(count2 > N / 3) ans.push_back(ele2);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}