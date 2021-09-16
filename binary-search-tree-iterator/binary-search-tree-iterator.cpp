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
class BSTIterator {
public:
    int inStore[10001];
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return inStore[curr++];
    }
    
    bool hasNext() {
        
        return curr < pos;
    }

private :
    int curr = 0;
    int pos = 0;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root -> left);
        inStore[pos++] = root -> val;
        inorder(root -> right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */