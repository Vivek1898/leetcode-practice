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
   int f(TreeNode * node, int mn , int mx){
        if(!node)return 0;
        mx=max(node->val,mx);
        mn=min(node->val,mn);
        int l=f(node->left,mn,mx);
        int r=f(node->right,mn,mx);
        return max(mx-mn,max(l,r));
    }
    
    int maxAncestorDiff(TreeNode* root) {
       return f(root,root->val, root->val);
    }
};