class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &ans,int target,int idx,  vector < int >& curr){
        
      
            if(target==0){
                ans.push_back(curr);
                return;
            }
           
        for(int i=idx;i<nums.size() ;i++){
             if (i > idx && nums[i] == nums[i - 1]) continue;
             if (nums[i] > target) break;
            curr.push_back(nums[i]);
             helper(nums,ans,target-nums[i],i+1,curr);
            curr.pop_back();
        }
      
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
            vector < int > curr;
        sort(candidates.begin(), candidates.end());
       //  vector < bool > vis(candidates.size(),false);
        helper(candidates,ans,target,0,curr);
        return ans;
    }
};