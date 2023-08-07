/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head) return head;
        int len = 1;
        ListNode *cur = head;
        while(cur -> next){
            len++;
            cur = cur -> next;
        }
        k %= len;
        if(!k) return head;

        cur -> next = head;
        cur = head;
        k = len - k - 1;
        while(k--){
            cur = cur -> next;
        }
        head = cur -> next;
        cur -> next = NULL;
        return head;
    }
};