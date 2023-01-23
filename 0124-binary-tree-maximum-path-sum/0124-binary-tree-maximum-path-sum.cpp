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

int maxPathSum(TreeNode* root) {
    int cnt=INT_MIN;
    chk(root, cnt);
    return cnt;
}
int chk(TreeNode* root, int& cnt){
    if(root==NULL){return 0;}
    int left= chk(root->left, cnt);
    int right= chk(root->right, cnt);
    left=max(left,0);
    right=max(right,0);
   int tempMax=left+right+root->val;
    cnt=max(cnt, tempMax);
    return root->val+max(left, right);
}
};