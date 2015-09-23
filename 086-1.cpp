/*
086. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* last = &dummy;
        ListNode* prev = &dummy;
        while(cur != NULL) {
            if(cur->val < x) {
                if(cur != last->next) {
                    ListNode* tmp = cur->next;
                    cur->next = last->next;
                    last->next = cur;
                    cur = tmp;
                    prev->next = cur;
                    last = last->next;
                } else {
                    prev = cur;
                    last = cur;
                    cur = cur->next;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
