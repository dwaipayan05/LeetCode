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
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        int left_height = checkHeight(root -> left);
        int right_height = checkHeight(root -> right);
        
        return abs(left_height - right_height) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }
    
    int checkHeight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        return 1 + max(checkHeight(root -> left), checkHeight(root -> right));
    }
};