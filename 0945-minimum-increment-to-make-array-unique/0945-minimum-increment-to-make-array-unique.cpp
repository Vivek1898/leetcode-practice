class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    
         if(nums.size()<2)
              return 0;
     int ans=0;   
   for(int i=1;i<nums.size();i++){
       if(nums[i]<=nums[i-1]){
      
           ans+=nums[i-1]+1-nums[i];
            nums[i]=nums[i-1]+1;
       }
   }
        return ans;
    }
};