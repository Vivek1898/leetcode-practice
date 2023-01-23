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
    void solve(TreeNode* root,int sum ,vector<vector<int>>&all,  vector<int>&curr){
        if(root==nullptr){
            return ;
        }
        curr.push_back(root->val);
        
        if(root->val==sum and root->right==nullptr and root->left==nullptr){
            all.push_back(vector<int>(curr));
        }else{
            solve(root->left,sum-root->val,all,curr);
            solve(root->right,sum-root->val,all,curr);
        }
        curr.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      
     
        vector<vector<int>>all;
        vector<int>curr;
        solve(root,sum,all,curr);
        return all;
    
    
    }
};