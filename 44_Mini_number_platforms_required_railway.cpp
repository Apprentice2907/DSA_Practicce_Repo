// Optimal solution
// Time Complexity:O(nlogn)+O(nlogn)+O(n) -- Total:O(NlogN)

class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        sort(Arrival.begin(), Arrival.end()); // didnt understand as sorting both arrays but mathematically it works so no worries
        sort(Departure.begin(), Departure.end());
        int plat=1;
        int maxi=1;
        int i=1;
        int j=0;
        while(i<Arrival.size() && j<Departure.size()){
            if(Arrival[i]<=Departure[j]){
                plat++;
                i++;
            }
            else if(Arrival[i]>Departure[j]){
                plat--;
                j++;
            }
            if(plat>maxi) maxi=plat;
        }
        return maxi;
    }
};