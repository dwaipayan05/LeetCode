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
    unordered_map<int, int> mp;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n  = inorder.size();
        
        for(int i = 0 ; i < n ; i++)
            mp[inorder[i]] = i;
        
        return constructTree(preorder, inorder, 0, n-1, 0);
        
    }
    
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preIndex)
    {
        if(inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        
        int inIndex = mp[root -> val];
        
        root -> left  = constructTree(preorder, inorder, inStart, inIndex - 1, preIndex + 1 );
        root -> right = constructTree(preorder, inorder, inIndex + 1, inEnd, inIndex - inStart + 1 + preIndex);
        
        return root;
    }
};