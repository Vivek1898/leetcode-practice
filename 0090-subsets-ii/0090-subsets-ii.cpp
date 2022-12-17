
//Recursion
class Solution2 {
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


// bfs


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>powerset;
        powerset.push_back({});
        int startIdx=0,endIdx=0;
        // if duplicte
        // then start from last genreted subset
        for(int i=0;i<nums.size();i++){
            startIdx=0;
            
            if(i>0 and nums[i]==nums[i-1]){
                startIdx=endIdx+1;
            }
            
            endIdx=powerset.size()-1;
            for(int j=startIdx;j<=endIdx;j++){
                  vector<int>copy(powerset[j]);
                    copy.push_back(nums[i]);
                        powerset.push_back(copy);
            }
            
        }
        return powerset;
    }
};