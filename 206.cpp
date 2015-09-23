/*
206. Reverse Linked List

Reverse a singly linked list.
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
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* beg = &dummy;
        ListNode* cur = beg->next;
        ListNode* move = cur->next;
        while(cur->next != NULL) {
            move = cur->next;
            cur->next = move->next;
            move->next = beg->next;
            beg->next = move;
        }
        return dummy.next;
    }
};
