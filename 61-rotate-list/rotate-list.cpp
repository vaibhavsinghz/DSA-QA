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
        if(k == 0 || !head) return head;
        int len = 0;
        ListNode* t1 = head, *t2 = head;
        while(t1){
            len++;
            t1 = t1 -> next;
        }
        k %= len;
        if(k == 0) return head;
        k = len - k - 1;
        t1 = head;
        while(k--){
            t1 = t1 -> next;
        }
        head = t1 -> next;
        t1 -> next = NULL;
        t1 = head;
        while(t1 -> next){
            t1 = t1 -> next;
        }
        t1 -> next = t2;
        return head;
    }
};