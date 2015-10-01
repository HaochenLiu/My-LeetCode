/*
083. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;

        while(pre && cur) {
            if(pre->val == cur->val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }

        return head;
    }
};
