class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &ans,int target,int idx,  vector < int > curr){
        
        if(idx==nums.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        //pick
        if(nums[idx]<=target){
            curr.push_back(nums[idx]);
             helper(nums,ans,target-nums[idx],idx,curr);
            //backtrack for yes
            curr.pop_back();
        }
        // dont pick
         helper(nums,ans,target,idx+1,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
            vector < int > curr;
        helper(candidates,ans,target,0,curr);
        return ans;
    }
};