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
  int longestZigZag(TreeNode* root) {
    return std::max({ dfs(root, 'L', 0), dfs(root, 'R', 0) }) - 1;
  }

private:
  int dfs(TreeNode* root, char direction, int steps) {
    if (!root)
      return steps;
    
    if (direction == 'L')
      return std::max(dfs(root->right, 'R', steps + 1), dfs(root->right, 'L', 0));
    else
      return std::max(dfs(root->left, 'L', steps + 1), dfs(root->left, 'R', 0));

    return 0;
  }
};