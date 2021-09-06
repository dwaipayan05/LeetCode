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
    bool isValidBST(TreeNode* root) {
        
        return validateBST(root, NULL, NULL);
    }
    
    bool validateBST(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if(root == NULL)
            return true;
        
        if(left != NULL && root -> val <= left -> val)
            return false;
        
        if(right != NULL && root -> val >= right -> val)
            return false;
        
        return validateBST(root->left, left, root) && validateBST(root->right, root, right);
        
    }
};