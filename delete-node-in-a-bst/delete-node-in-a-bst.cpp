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
    TreeNode* findMin(TreeNode* root){
        if(root -> left == NULL) return root;
        return findMin(root -> left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        else if(key < root -> val) root -> left = deleteNode(root -> left, key);
        else if(key > root -> val) root -> right = deleteNode(root -> right, key);
        else{
            if(!root -> left and !root -> right) return NULL;
            else if(!root -> left) return root -> right;
            else if(!root -> right) return root -> left;
            else{
                TreeNode* successor = findMin(root -> right);
                root -> val = successor -> val;
                root -> right = deleteNode(root -> right, successor -> val);
            }
        }
        return root;
    }
};