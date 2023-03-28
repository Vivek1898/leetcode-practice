class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
      //  int f=nums[0];
        ans[0]=nums[0];
        for(int i=1;i<nums.size();i++){
          //  ans.push_back(nums[i]+f);
            ans[i]=ans[i-1]+nums[i];
           // f=nums[i];
        }
        
        return ans;
        
        
    }
};