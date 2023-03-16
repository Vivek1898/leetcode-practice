class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       int n = inorder.size();
    int m = postorder.size();
    if (n == 0 || m == 0)
    {
      return NULL;
    }
    int rootVal = postorder[m - 1];
    TreeNode *root = new TreeNode(rootVal);
    int rootIndex = -1;
    for (int i = 0; i < n; i++)
    {
      if (inorder[i] == rootVal)
      {
        rootIndex = i;
        break;
      }
    }
    vector<int> inLeft(inorder.begin(), inorder.begin() + rootIndex);
    vector<int> inRight(inorder.begin() + rootIndex + 1, inorder.end());
    vector<int> postLeft(postorder.begin(), postorder.begin() + inLeft.size());
    vector<int> postRight(postorder.begin() + inLeft.size(), postorder.end() - 1);
    root->left = buildTree(inLeft, postLeft);
    root->right = buildTree(inRight, postRight);
    return root;  
    }
};