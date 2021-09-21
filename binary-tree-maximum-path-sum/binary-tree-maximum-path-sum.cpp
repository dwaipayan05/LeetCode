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
    int answer;
    
    int dfs(TreeNode* root)
    {
       if(root == NULL) 
           return 0;
        
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        
        answer = max(answer, root->val + leftSum + rightSum);
        
        return max(0, root->val + max(leftSum, rightSum));
    }
    
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }
};