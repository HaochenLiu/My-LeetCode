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
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;

        while(cur->next) {
            if(cur->next->val < x) {
                cur = cur->next;
            } else {
                break;
            }
        }
        if(cur->next == NULL) return head;
        
        ListNode* next = cur->next;
        while(next->next) {
            if(next->next->val < x) {
                ListNode* move = next->next;
                next->next = move->next;
                move->next = cur->next;
                cur->next = move;
                cur = cur->next;
            } else {
                next = next->next;
            }
        }

        return dummy.next;
    }
};
