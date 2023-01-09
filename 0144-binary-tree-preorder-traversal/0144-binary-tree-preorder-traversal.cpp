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
private:
    std::vector<int> kids;
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        getKid(root);
        return kids;
    }
    void getKid(TreeNode* root) {
        if(!root) return; 
        kids.push_back(root->val);
        getKid(root->left);
        getKid(root->right);
    }
};