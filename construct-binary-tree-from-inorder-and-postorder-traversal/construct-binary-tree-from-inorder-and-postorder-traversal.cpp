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
    unordered_map<int, int>mp;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();

        for(int i = 0 ; i < n ; i++)
            mp[inorder[i]] = i;
        
        return constructTree(inorder, postorder, 0, n-1, n-1);
    }
    
    
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int poIndex)
    {
        if(inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[poIndex]);
        int inIndex = mp[root -> val];
        
        root -> right = constructTree(inorder, postorder, inIndex + 1, inEnd, poIndex -1);
        root -> left = constructTree(inorder, postorder, inStart, inIndex-1,  poIndex + inIndex - 1 - inEnd);
        
        return root;
        
    }
};

//Length of Right Subtree (In terms of Inorder)
// inEnd - (inIndex + 1) + 1
//Position of Next Root
// poIndex - (inEnd - (inIndex + 1) + 1) - 1
// poIndex - (inEnd - inIndex - 1 + 1) - 1
// poIndex - (inEnd - inIndex) -1
// poIndex + inIndex - inEnd - 1