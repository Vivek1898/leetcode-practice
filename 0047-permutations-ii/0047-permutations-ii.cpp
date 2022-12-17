class Solution {
public:

    
      void helper(vector<int>& nums,int idx,vector<int>& currPerm,vector<vector<int>>& res,vector<bool>& visited){
         if(idx == nums.size()){
            res.push_back(currPerm);
            return ;
        }else{
             // ADD CURRENT NO AT EVERY POSITION
 for(int i=0;i<nums.size();i++)
     {
                 
        if (visited[i])
            continue;
 
      
        if (i > 0 and nums[i] == nums[i - 1]
            and !visited[i - 1])
            continue;
 
        visited[i] = true;
        currPerm.push_back(nums[i]);
       helper(nums,idx+1, currPerm,res, visited);
 
        visited[i] = false;
        currPerm.pop_back();
             }
         }
    }  
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
         vector<int> currPerm;
        vector<bool> visited((int)nums.size(), false);
         sort(nums.begin(), nums.end());
        helper(nums,0,currPerm,res,visited);
        return res;   
    }
    
  
};