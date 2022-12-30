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
    bool dfs(TreeNode* root){
        if(root==NULL) return false;
        bool a=dfs(root->left);
        bool b=dfs(root->right);
        if(root->val ==1 || root->val==0) return (bool)root->val;
        if(root->val==2){
            return a||b;
        }
        return a&&b;
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};