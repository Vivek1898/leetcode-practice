//BFS
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>powerset;
        powerset.push_back({});
        for(auto currentNumber:nums){
            int n=powerset.size();
            for(int i=0;i<n;i++){
                // duplicates + new
                  vector<int>copy(powerset[i]);
                    copy.push_back(currentNumber);
                        powerset.push_back(copy);
            }
            
        }
        return powerset;
        
    }
};

//Recursion

class Solution {
public:
    void helper(vector<int>& nums,  vector<int> &curr,vector<vector<int>> &ans,int idx){
        if(idx==nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        // pick and add
        curr.push_back(nums[idx]);
         helper(nums,curr,ans,idx+1);
        curr.pop_back();
        // not pick
         helper(nums,curr,ans,idx+1);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
         vector<int> curr;
        helper(nums,curr,ans,0);
        return ans;
        
    }
};