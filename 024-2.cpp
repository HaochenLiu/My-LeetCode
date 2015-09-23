/*
024. Swap Nodes in Pairs
O(n)

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* cur = ins->next;
        while(cur && cur->next) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
            ins = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};
