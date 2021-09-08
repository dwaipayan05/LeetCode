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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        vector<vector<int>> lvlOrderTraversed;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            vector<int>lvl;
            while(n > 0)
            {
                TreeNode* Node = q.front();
                lvl.push_back(Node -> val);  
                q.pop();
                
                if(Node->left != NULL)
                    q.push(Node->left);
                
                if(Node->right != NULL)
                    q.push(Node->right);
                
                n--;
            }
            
            lvlOrderTraversed.push_back(lvl);
        }
        
        return lvlOrderTraversed;
        
    }
};