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
    int Prev_Sum = 0;
    
    void reverseInorder(TreeNode* root)
    {
        if(!root)
            return;
        
        if(root -> right)
            reverseInorder(root->right);
        cout << Prev_Sum << endl;
        Prev_Sum += root->val;
        root->val = Prev_Sum;
        
        if(root -> left)
            reverseInorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        
        reverseInorder(root);
        return root;
    }
};