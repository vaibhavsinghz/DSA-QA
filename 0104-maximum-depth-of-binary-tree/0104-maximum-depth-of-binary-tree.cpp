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
        // if(root -> left != NULL) counth(root -> left);
        // if(root -> right != NULL) counth(root -> right);
        // count++;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(root -> left == NULL && root -> right == NULL) return 1;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};