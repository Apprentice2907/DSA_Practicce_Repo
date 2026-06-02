// My approach (Better approach)
// Time Complexity-O(mn)-as (2*mn) but ignoring constant (mn)
// Space complexity O(m+n)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    unordered_set<int> rows;
    unordered_set<int> cols;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(rows.count(i) || cols.count(j)){
                matrix[i][j]=0;
            }
        }
    }

    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}









// Optimal approach while space complexity O(1)

class Solution {
public:
    // Function to set entire row and column to 0 if an element in the matrix is 0 (Optimal O(1) space)
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstr=0;
        bool firstc=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(i==0) firstr=true;
                    if(j==0) firstc=true;
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstr){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        if(firstc){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};


int main() {
    Solution obj;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    obj.setZeroes(matrix);
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}