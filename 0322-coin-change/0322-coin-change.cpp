class Solution
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        // for (int i = 1; i <= amount; ++i)
        //     for (auto & c : coins)
        //         if (i - c >= 0 && dp[i - c] != -1)
        //             dp[i] = dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;
        
     //   
        //  for(int index = 1 ; index < dp.size() ; index++)
        // {   
        //     for(int j = 0 ; j < coins.size() ; j++)
        //     {
        //         if(coins[j] <= index)
        //             dp[index] = min(dp[index],dp[index-coins[j]]+1);
        //         // 1 -for current coin
        // }
        // }
        
        //1 for current coin
        for(int c:coins){
            for(int i=c;i<=amount ;i++){
                dp[i] = min(dp[i],dp[i-c]+1);
            }
        }
        return (dp[amount] > amount ) ? -1 : dp[amount];
    }
};