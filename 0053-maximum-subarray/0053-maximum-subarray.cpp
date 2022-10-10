class Solution {
public:
    int DP(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp(100000,0);
         dp[0]=nums[0]>0?nums[0]:0;
            
             int maxi=0;
            for(int i=1;i<nums.size();i++){
                dp[i]=dp[i-1]+nums[i];
                   maxi=max(dp[i],maxi);
            }
     
         
        return maxi;
    }
    
    
      int maxSubArray(vector<int>& nums) {
         int csum=0;
          int maxi=nums[0];
          for(int i=0;i<nums.size();i++){
              csum+=nums[i];
               maxi=max(csum,maxi);
            if(csum<0) csum=0;
          }
          
         return maxi;
          
    }
};