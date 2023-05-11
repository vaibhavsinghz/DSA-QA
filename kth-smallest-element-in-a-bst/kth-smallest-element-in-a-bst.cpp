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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, count = 0;
        TreeNode* cur = root;
        while(cur){
            if(!cur -> left) {
                count++;
                if(count == k) ans = cur -> val;
                cur = cur -> right;
            }
            else{
                TreeNode* temp = cur -> left;
                while(temp -> right and temp -> right != cur) temp = temp -> right;
                if(!temp -> right){
                    temp -> right = cur;
                    cur = cur -> left;
                }
                else{
                    temp -> right = NULL;
                    count++;
                    if(count == k) ans = cur -> val;
                    cur = cur -> right;
                }
            }
        }
        return ans;
    }
};