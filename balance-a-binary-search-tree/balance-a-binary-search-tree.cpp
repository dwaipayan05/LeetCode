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
    vector<TreeNode*> inorder;
    
    void storeInorder(TreeNode* root)
    {
        if(!root)
            return;
        
        storeInorder(root->left);
        inorder.push_back(root);
        storeInorder(root->right);
    }
  
    TreeNode* buildTree(vector<TreeNode*> & inorder, int start , int end)
    {
        if(start > end)
            return NULL;
        
        int mid = (start + end)/2;
        TreeNode* root = inorder[mid];
        
        root -> left = buildTree(inorder, start, mid-1);
        root -> right = buildTree(inorder, mid+1, end);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        inorder = {};
        storeInorder(root);
        
        int n = inorder.size();
        cout << n << endl;
        
        return buildTree(inorder, 0, n-1);
    }
};