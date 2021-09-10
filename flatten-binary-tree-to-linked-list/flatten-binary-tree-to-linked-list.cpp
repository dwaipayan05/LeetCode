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
    void flatten(TreeNode* root) {
        
        if(root != NULL)
        {
            TreeNode* temp = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
            
            TreeNode* Node = root;
            
            while(Node -> right)
            {
                Node = Node -> right;
            }
            
            Node -> right = temp;
            flatten(root -> right);
        }
        
        return;
    }
};