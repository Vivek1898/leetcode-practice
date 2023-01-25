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
    long long subTree=0;
     long long totalSum=0;
    //int ans=0;
     long long ans=0;
     long long mod=1e9+7;
    void total(TreeNode*root){
        if(!root) return;
        totalSum+=root->val%mod;
        total(root->left);
         total(root->right);
        
    }
    int solve(TreeNode* root){
        if(!root) return 0 ;
        subTree=solve(root->right) + solve(root->left) + root->val;
        int b=totalSum-subTree;
        ans=max(ans,subTree*b);
        
       subTree= subTree%mod;
        return subTree;
    }
    int maxProduct(TreeNode* root) {
        total(root);
    solve(root);
        return ans%mod;
        
        
    }
};