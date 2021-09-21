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
    int prev_sum = 0;
    void reverseInorder(TreeNode* root)
    {
        if(!root)
            return;
        
        if(root->right)
            reverseInorder(root->right);
        
        prev_sum += root->val;
        root->val = prev_sum;
        
        if(root->left)
            reverseInorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        reverseInorder(root);
        return root;
    }
};