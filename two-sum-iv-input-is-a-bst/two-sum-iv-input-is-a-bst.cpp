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
    vector<int>vec;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
        
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        
        int l = 0;
        int r = vec.size()-1;
        
        while(l < r)
        {
            if(vec[l] + vec[r] == k)
                return true;
            else if(vec[l] + vec[r] > k)
                r--;
            else 
                l++;
        }
        
        return false;
    }
};