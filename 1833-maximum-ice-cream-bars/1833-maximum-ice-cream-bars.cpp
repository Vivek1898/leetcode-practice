class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
       int n=costs.size();
        int ans=0;
        int i=0;
        while(coins>0 && i<n){
            if(costs[i]<=coins){
                ans++;
                coins-=costs[i];
                i++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};