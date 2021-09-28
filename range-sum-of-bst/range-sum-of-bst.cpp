class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;
    return ((root->val>=L && root->val<=R)? (root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R)) : (root->val<L)? rangeSumBST(root->right,L,R): rangeSumBST(root->left,L,R));
    }
};