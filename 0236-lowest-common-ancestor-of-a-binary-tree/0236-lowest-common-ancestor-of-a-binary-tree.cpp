/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define null NULL
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==null or root==p or root==q) return root;
        
        
          TreeNode* lt= lowestCommonAncestor(root->left,p,q);
          TreeNode* rt= lowestCommonAncestor(root->right,p,q);
        
        if(!lt)  return rt;
        else if(!rt)  return lt;
        else return root;
        
    }
};