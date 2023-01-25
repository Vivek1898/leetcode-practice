class Solution {
public:
    void search(vector<int>& nums,int target,int left, vector<vector<int>>& trip){
        int right=nums.size()-1;
        while(left<right){
            int csum=nums[left]+nums[right];
            if(csum==target){
                
                trip.push_back({-target,nums[left],nums[right]});
                left++;
                right--;
                
                while(left<right and nums[left]==nums[left-1]) left++;
                while(left<right and nums[right]==nums[right+1]) right--;
                
            }else if(target>csum){
                left++;
            }else{
                right--;
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> trip;
         sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            // a+b+c=0
            //b+c=0-a
            search(nums,-nums[i],i+1,trip);
        }
        return trip;
    }
};