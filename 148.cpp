/*
148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        ListNode* cur = head;
        while(l1 || l2) {
            if(!l1) {
                cur->next = l2;
                break;
            }
            
            if(!l2) {
                cur->next = l1;
                break;
            }
            
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        return head->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        
        return mergeTwoLists(l1, l2);
    }
};
