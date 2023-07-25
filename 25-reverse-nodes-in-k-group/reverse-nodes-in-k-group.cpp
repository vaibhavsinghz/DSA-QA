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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* nodePrev = dummy;
        while(true){
            ListNode* kth = kthNode(nodePrev, k);
            if(!kth) break;
            ListNode* nodeNext = kth -> next;
            //reverse LL
            ListNode* prev = nodeNext, *cur = nodePrev -> next;
            while(cur != nodeNext){
                ListNode* tmp = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = tmp;
            }
            ListNode* tmp = nodePrev -> next;
            nodePrev -> next = kth;
            nodePrev = tmp;
        }
        return dummy -> next;
    }
    ListNode* kthNode(ListNode* head, int k){
        while(head and k){
            head = head -> next;
            k--;
        }
        return head;
    }
};