

class Solution {
public:
    void helper(vector<int>& nums,  vector<int> &curr,vector<vector<int>> &ans,int idx){
      //  if(idx==nums.size()) {
            ans.push_back(curr);
        //     return;
        // }
        
        for(int i=idx;i<nums.size();i++){
            
            if(i>idx and nums[i]==nums[i-1]) continue;
               curr.push_back(nums[i]);
         helper(nums,curr,ans,i+1);
        curr.pop_back();
        }
        // pick and add
     
        // not pick
        // helper(nums,curr,ans,idx+1);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
         vector<int> curr;
        helper(nums,curr,ans,0);
        return ans;
        
    }
};