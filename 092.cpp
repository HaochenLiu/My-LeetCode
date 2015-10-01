/*
092. Reverse Linked List II

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/*
Time: O(n)
Space: O(1)
Extra space: O(1)
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL || m == n) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        for(int i = 0; i < m - 1; i++) {
            ins = ins->next;
        }

        ListNode* cur = ins->next;
        for(int i = 0; i < n - m; i++) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
        }

        return dummy.next;
    }
};
