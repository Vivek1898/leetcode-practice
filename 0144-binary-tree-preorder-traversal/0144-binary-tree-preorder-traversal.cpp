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
        if(root==nullptr) return {};
       stack<TreeNode*>s;
        vector<int>ans;
        s.push(root);
        while(!s.empty()){
            TreeNode* top=s.top();
            s.pop();
            ans.push_back(top->val);
            if(top->right) s.push(top->right);
            if(top->left) s.push(top->left);
            
        }
        return ans;
    }
   
};


class SolutionRECURSION {
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