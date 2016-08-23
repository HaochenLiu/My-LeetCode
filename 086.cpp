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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while(pre->next != NULL && pre->next->val < x) {
            pre = pre->next;
        }
        if(pre->next == NULL) {
            return dummy.next;
        }
        cur = pre->next;
        while(cur->next != NULL) {
            if(cur->next->val < x) {
                ListNode* move = cur->next;
                cur->next = move->next;
                move->next = pre->next;
                pre->next = move;
                pre = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
