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
    void invert(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        if(root -> left == NULL && root -> right == NULL)
            return;
            
        else if(root -> left == NULL)
        {
            root -> left = root -> right;
            root -> right = NULL;
        }
        
        else if(root -> right == NULL)
        {
            root -> right = root -> left;
            root -> left = NULL;
        }
        
        else
        {
            TreeNode* temp = root -> left;
            root -> left = root -> right;
            root -> right = temp;
        }

    
        invert(root -> left);
        invert(root -> right);
        
        return;
        
    }
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return root;
        
        invert(root);
        
        return root;
    }
};