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
    int countNodes(TreeNode* root) {
        int l=0;
        int r=0;
        TreeNode* leftPtr=root;
         TreeNode* rightPtr=root;
        if(!root) return 0 ;
        
        while(leftPtr) {
            leftPtr=leftPtr->left;
            l++;
        }
        while(rightPtr) {
            rightPtr=rightPtr->right;
            r++;
        }
        
        if(l==r) return pow(2,l)-1;
        return 1+countNodes(root->left) +countNodes(root->right);
        
    }
};