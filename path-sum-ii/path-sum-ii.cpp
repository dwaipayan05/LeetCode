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
private : 
    vector<vector<int>> ListOfPath;
public:
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return ListOfPath;
        
        vector<int>Curr_Path;
        
        findpathSum(root, targetSum, Curr_Path);
        return ListOfPath;
    }
    
    void findpathSum(TreeNode* root, int targetSum, vector<int> Curr_Path)
    {
        if(root == NULL)
            return;
        
        Curr_Path.push_back(root -> val);
        if(root -> left == root -> right && targetSum == root -> val)
        {
    
            ListOfPath.push_back(Curr_Path);
            return;
        }
        
        findpathSum(root->left, targetSum - root->val, Curr_Path);
        findpathSum(root->right, targetSum - root->val, Curr_Path);
        
    }
};