/*
086. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;

        ListNode small(0);
        ListNode large(0);
        ListNode* pre1 = &small;
        ListNode* pre2 = &large;
        ListNode* cur = head;
        while (cur != NULL) {
            if (cur->val < x) {
                pre1->next = cur;
                pre1 = pre1->next;
            } else {
                pre2->next = cur;
                pre2 = pre2->next;
            }
            cur = cur->next;
        }
        pre1->next = large.next;
        pre2->next = NULL;
        return small.next;
    }
};
