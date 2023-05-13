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
    void findodr(TreeNode* root, vector <int> &inodr){
        if(!root) return;
        findodr(root -> left, inodr);
        inodr.push_back(root -> val);
        findodr(root -> right, inodr);
    }
    int i = 0;
    void recover(TreeNode* &root, vector <int> &inodr){
        if(!root) return;
        recover(root -> left, inodr);
        if(root -> val != inodr[i]){
            root -> val = inodr[i];
        }
        i++;
        recover(root -> right, inodr);
    }
    void recoverTree(TreeNode* root) {
        vector <int> inodr;
        findodr(root, inodr);
        sort(inodr.begin(), inodr.end());
        recover(root, inodr);
    }
};