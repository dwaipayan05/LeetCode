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
    vector<TreeNode*> constructTrees(int s, int e)
    {
        vector<TreeNode*> res;
        if(s > e)
        {
            res.push_back(NULL);
            return res;
        }
        
        for(int i = s; i <= e; i++)
        {
            vector<TreeNode*> leftSubtree = constructTrees(s, i-1);
            vector<TreeNode*> rightSubtree = constructTrees(i+1, e);
            
            for(int j = 0; j < leftSubtree.size(); j++)
            {
                TreeNode* left = leftSubtree[j];
                for(int k = 0 ; k < rightSubtree.size(); k++)
                {
                    TreeNode* right = rightSubtree[k];
                    TreeNode* node = new TreeNode(i); 
                    node -> left = left;
                    node -> right = right;
                    res.push_back(node);
                    
                }
            }
        }
        
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*> res;
        res = constructTrees(1, n);
        return res;
    }
};