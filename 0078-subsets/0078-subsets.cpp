class Solution {
public:
     void helper (vector<int>& nums , vector<int>&curr ,  vector<vector<int>>&ans , int idx){
         if(idx==nums.size())
         {
             ans.push_back(curr);
             return;
         }
       
         curr.push_back(nums[idx]);
         helper(nums,curr,ans,idx+1);
         curr.pop_back();
         helper(nums,curr,ans,idx+1);
         
     }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
       helper(nums,curr,ans,0);
         return ans;
        
        
    }
};