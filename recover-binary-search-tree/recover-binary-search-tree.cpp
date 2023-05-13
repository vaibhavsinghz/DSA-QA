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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL, *first = NULL, *mid = NULL, *last = NULL;
        TreeNode* cur = root;
        while(cur){
            if(!cur -> left){
                if(prev and cur -> val < prev -> val){
                    if(!first){
                        first = prev;
                        mid = cur;
                    }
                    else last = cur;
                }
                prev = cur;
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
                    if(prev and cur -> val < prev -> val){
                        if(!first){
                            first = prev;
                            mid = cur;
                        }
                        else last = cur;
                    }
                    prev = cur;
                    cur = cur -> right;
                }
            }
        }
        cout << first -> val <<endl;
        if(first and last) swap(first -> val, last -> val);
        else if(first and mid) swap(first -> val, mid -> val);
    }
};