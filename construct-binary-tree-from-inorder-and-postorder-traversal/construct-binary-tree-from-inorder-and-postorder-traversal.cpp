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
    int pStart;
    TreeNode* helper(vector<int>& postorder, unordered_map <int, int> &inodr, int iStart, int iEnd){
        if(iStart > iEnd) return NULL;
        int curRoot = postorder[pStart];
        pStart--;
        TreeNode* root = new TreeNode(curRoot);
        if(iStart == iEnd) return root;
        int mid = inodr[curRoot];
        root -> right = helper(postorder, inodr, mid + 1, iEnd);
        root -> left = helper(postorder, inodr, iStart, mid - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map <int, int> inodr;
        for(int i = 0; i < inorder.size(); ++i){
            inodr[inorder[i]] = i;
        }
        pStart = postorder.size() - 1;
        return helper(postorder, inodr, 0, inorder.size() - 1);
    }
};