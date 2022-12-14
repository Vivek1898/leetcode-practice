// class Solution
// {
// public:
//     void helper(vector<int> &nums, int idx, vector<int> &currPerm, vector<vector<int>> &res, vector<bool> &visited)
//     {
//         if (idx == nums.size())
//         {
//             res.push_back(currPerm);
//             return;
//         }
//         else
//         {
//             // ADD CURRENT NO AT EVERY POSITION
//             for (int i = 0; i < nums.size(); i++)
//             {
//                 if (visited[i])
//                     continue;
                
//                 if (i > 0 and nums[i] == nums[i - 1] and !visited[i - 1])
//                     continue;

//                 visited[i] = true;
//                 currPerm.push_back(nums[i]);
//                 helper(nums, idx + 1, currPerm, res, visited);

//                 visited[i] = false;
//                 currPerm.pop_back();
//             }
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int> &nums)
//     {
//         vector<vector<int>> res;
//         vector<int> currPerm;
//         vector<bool> visited((int)nums.size(), false);
//         sort(nums.begin(), nums.end());
//         helper(nums, 0, currPerm, res, visited);
//         return res;
//     }
// };




class Solution {
public:
    
    void helper(vector<int>& cand, vector<int> &num,vector<vector<int>> &ans,int n, map<int,int>& m){
        //found 
        if(num.size() == n){
            ans.push_back(num);
            return;
        }
        for (auto i = m.begin(); i != m.end(); ++i){
            if(i->second > 0){
                
                num.push_back(i->first);
                i->second--;
                helper(cand,num,ans,n,m);
                
                // backtracking
                // for future permutations
                i->second++;
                num.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> m;
        for(auto x: nums) m[x]++;
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> num;
        helper(nums,num,ans,n,m);
        return ans;
    }
};