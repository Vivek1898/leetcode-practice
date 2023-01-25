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
    int count=0;
     
    int solve(TreeNode* root,int mx,int &cnt){
        if(!root) return 0 ;
        
      if(root->val>=mx){
          cnt++;
          cout<<cnt<<endl;
          mx=root->val;
      }
       // mx=max(mx,root->val);
        
        
   int a=   solve(root->left,mx,cnt);
    int b=   solve(root->right,mx,cnt);
        return cnt;
        
     //   return (a+b+mx<=root->val);
        
    }
    int goodNodes(TreeNode* root) {
     //  int mx=INT_MIN;
       // int count=0;
        int cnt=0;
        return solve(root,root->val,cnt);;
            
    }
};
class Solution1 {
public:
    int count=0;
     
    void solve(TreeNode* root,int mx){
        if(!root) return ;
        
      if(root->val>=mx){
          count++;
          mx=root->val;
      }
       // mx=max(mx,root->val);
        
        
       solve(root->left,mx);
       solve(root->right,mx);
        
     //   return (a+b+mx<=root->val);
        
    }
    int goodNodes(TreeNode* root) {
       int mx=INT_MIN;
       // int count=0;
        solve(root,root->val);
        return count;
            
    }
};