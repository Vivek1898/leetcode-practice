class Solution {
public:
    int houseRob(vector<int>& num){
        int n=num.size();
        int dp[n];
        dp[0]=num[0];
        dp[1]=max(num[0],num[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+num[i]);
        }
        return dp[n-1];
        
    }
    int rob(vector<int>& nums) {
        // minor cases
          int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
        // two choics either use 
        // 1st house OR
        
        // Second House
         vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        
        int ans=max(houseRob(v1), houseRob(v2));
        return ans;
        
        
    }
};