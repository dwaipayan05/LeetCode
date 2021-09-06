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
        
        queue<TreeNode*>q;
        q.push(root);
        
        vector<vector<int>>lvlTraversal;
        
        while(!q.empty())
        {
            vector<int>level;
            
            int NodeCount = q.size();
            
            while(NodeCount > 0)
            {
                TreeNode* Node = q.front();
                level.push_back(Node -> val);  
                
                q.pop();
            
                if(Node -> left != NULL)q.push(Node -> left);            
                if(Node -> right != NULL) q.push(Node -> right);
                
                NodeCount--;
             }
            
            lvlTraversal.push_back(level);
            
        }
        
        return lvlTraversal;
        
    }
};