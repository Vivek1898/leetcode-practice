class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow=0,sum=0,minLen=INT_MAX;
        
        for(int fast=0;fast<nums.size();fast++){
            sum+=nums[fast];
            
            while(sum>=target){
                minLen=min(minLen,fast-slow+1);
                //Exclude
                sum-=nums[slow];
                slow++;
            }
        }
        //No valiad
        if(minLen == INT_MAX) return 0;
        return minLen;
        
    }
};