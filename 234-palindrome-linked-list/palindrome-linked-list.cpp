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
    void printList(ListNode* head){
        while(head){
            cout<<head -> val<<endl;
            head = head -> next;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(!head -> next) return true;
        ListNode* slow = head, *fast = head;
        if(!fast -> next -> next) return slow -> val == slow -> next -> val;
        ListNode* prev = NULL, *cur = head, *tmp = NULL;
        while(fast and fast -> next and fast -> next -> next){
            fast = fast -> next -> next;
            tmp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = tmp;
            // slow = slow -> next;
        }
        tmp = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = tmp;
        // printList(prev);
        // printList(cur);
        if(fast -> next){
            slow = prev;
            fast = cur;
        }
        else{
            slow = prev -> next;
            fast = cur;
        }
        // printList(slow);
        printList(fast);
        while(slow){
            if(slow -> val != fast -> val) return false;
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
};