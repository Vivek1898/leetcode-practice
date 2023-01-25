/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
   // int count=0;
  int solve(TreeNode* root,int &count){
        if(!root) return 0;
        int left=solve(root->left,count);
        int right = solve(root->right,count);
         int sum=left+right+root->val;  
        mp[sum]++;
         count=max(count,mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int count=0;
        solve(root,count);
        vector<int>ans;
        for(auto it:mp)
            if(it.second==count)
                ans.push_back(it.first);
        return ans;
       
    }
};