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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return isSame(root -> left, root -> right);
    }
    
    bool isSame(TreeNode* p, TreeNode* q)
    {
        if(p == NULL || q == NULL)
            return p == q;
        else
            return p->val == q->val && isSame(p->left, q->right) && isSame(p->right, q->left);
        
    }
};