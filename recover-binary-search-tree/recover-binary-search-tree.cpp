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
    vector<pair<TreeNode*, TreeNode*>>WrongPairs;
    TreeNode* prev = NULL;
    
    void inorderTraversal(TreeNode* root)
    {
        if(!root)
            return;
        
        inorderTraversal(root -> left);
        if(prev  && prev->val > root -> val)
            WrongPairs.push_back({prev, root});
        prev = root;
        inorderTraversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        
        inorderTraversal(root);
        if(WrongPairs.size() == 2)
            swap(WrongPairs[0].first -> val, WrongPairs[1].second->val);
        else if(WrongPairs.size() == 1)
            swap(WrongPairs[0].first -> val, WrongPairs[0].second->val);
    }
};