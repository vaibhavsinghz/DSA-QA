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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2) return NULL;
        int n1 = l1 ? l1 -> val : 0;
        int n2 = l2 ? l2 -> val : 0;
        int sum = n1 + n2;
        ListNode *newNode = new ListNode(sum % 10);
        sum = sum / 10;
        ListNode* carry = l1 ? l1 -> next : NULL;
        if(carry) carry -> val += sum;
        else if(sum) carry = new ListNode(sum);
        newNode -> next = addTwoNumbers(carry, l2 ? l2 -> next : NULL);
        return newNode;
    }
};