class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyday=0,sellday=0,profit=0;
        
        for(int i=0;i<prices.size()-1;i++){
            if(prices[buyday]>=prices[i]){
             buyday=i;
                sellday=i+1;
            }
            
            if(prices[sellday]-prices[buyday]>profit){
                profit=prices[sellday]-prices[buyday];
            }
            ++sellday;
            
           
        } 
        if(profit<=0) return 0;
         return profit;
    }
};