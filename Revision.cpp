// Set matrixes zero
// O(M*N) and O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool row=false;
        bool col=false;
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                row=true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                col=true;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(row){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};







// Pascal Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=tri[i-1][j-1]+tri[i-1][j];
            }
            tri.push_back(row);
        }
        return tri;   
    }
};




class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long val=1;
        int N=rowIndex;
        row.push_back(val);
        for(int k=1;k<=N;k++){
            val=val*(N-k+1)/k;
            row.push_back(val);
        }
        return row;
    }
};






// Next permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=nums.size()-1;i>idx;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1,nums.end());
    }
};






// Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi=LONG_MIN;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(sum>maxi) maxi=sum;
            if(sum<0) sum=0; 
        }
        return maxi;
    }
};






// Kadane's algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};






// Sell and buy stocks

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;   
        int minp=INT_MAX;
        for(int p:prices){
            if(p<minp) minp=p;
            else maxp=max(maxp,p-minp);
        }   
        return maxp;
    }
};




// Matrix 90 degreee

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};



// Subintervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto inter:intervals){
            if(ans.empty() || ans.back()[1]<inter[0]){
                ans.push_back(inter);
            }
            else{
                ans.back()[1]=max(ans.back()[1],inter[1]);
            }
        }
        return ans;
    }
};




// Duplicate number 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};








