class Solution {
public:
    bool consecutiveSetBits(int n) {
        vector<int> bits;
        while(n>0){
            bits.push_back(n&1);
            n=n>>1;
        }
        reverse(bits.begin(),bits.end());
        int count=0;
        for(int i=1;i<bits.size();i++){
            if(bits[i]==1 && bits[i-1]==1){
                count=count+1;
            }
        }
        if(count==1) return true;
        return false;
    }
};