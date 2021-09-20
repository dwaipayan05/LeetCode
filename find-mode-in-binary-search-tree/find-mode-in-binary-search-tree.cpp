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
    unordered_map<int,int>mp;
    
    void findModer(TreeNode* root)
    {   
        if(root!=NULL)
            mp[root->val]++;
        
        if(root->left && root->right)
        {
            findModer(root->left);
            findModer(root->right);
        }
        
        else if(root -> left)
            findModer(root->left);
        else if(root -> right)
            findModer(root->right);
        
        return;
    }
    vector<int> findMode(TreeNode* root) {
        findModer(root);
        
        int maxMode = 0;
        for(auto i : mp)
            maxMode = max(i.second, maxMode);
        
        vector<int> res;
        
        for(auto i : mp)
        {
            if(i.second == maxMode)
                res.push_back(i.first);
        }
        
        return res;
    }
};