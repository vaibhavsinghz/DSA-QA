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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        helper(root, dia);
        return dia;
    }
    int helper(TreeNode *root, int &d){
        if(!root) return 0;
        int lh = helper(root -> left, d);
        int rh = helper(root -> right, d);
        d = max(d, lh + rh);
        return 1 + max(lh, rh);
    }
};