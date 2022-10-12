class Solution {
public:
    int minMoves2(vector<int>& nums) {
       
        int sum=accumulate(nums.begin(),nums.end(),0);
        int small=*min_element(nums.begin(),nums.end());
        
        int ans=sum-(nums.size()*small);
        return ans;
    }
    
      int minMoves(vector<int>& nums) {
          
          int n=nums.size();
          sort(nums.begin(),nums.end());
          int ans=0;
          for(int i=0;i<n;i++){
              ans+=nums[i]-nums[0];
          }
       
//         int sum=accumulate(nums.begin(),nums.end(),0);
//         int small=*min_element(nums.begin(),nums.end());
        
//         int ans=sum-(nums.size()*small);
        return ans;
    }
};