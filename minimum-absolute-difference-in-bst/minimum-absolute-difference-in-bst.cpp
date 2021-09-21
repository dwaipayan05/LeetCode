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
    int ans, prev, curr;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        if(root->left)
            inorder(root->left);
        
        if(prev!=-1)
        ans = min(ans, abs(prev-root->val));
        prev = root->val;
        
        if(root->right)
            inorder(root->right);
        
     
    }
    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        prev = -1;
        inorder(root);
        
        return ans;
    }
};