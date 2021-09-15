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
    int sum(TreeNode* root, int prev)
    {
        if(root == NULL)
            return 0;
        
        int num = prev*10 + root->val;
        if(!root -> left && !root->right)
            return num;
        
        return sum(root->left, num) + sum(root->right, num);
    }
    int sumNumbers(TreeNode* root) {
        
        if(!root)
            return 0;
        
        return sum(root, 0);
    }
};