/*
024. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/*
Time: O(n)
Space: O(1)
n is number of nodes
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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = &dummy;
        ListNode* next;
        ListNode* tmp;
        while(cur->next && cur->next->next) {
            next = cur->next;
            tmp = next->next;
            cur->next = next->next;
            next->next = tmp->next;
            tmp->next = next;
            cur = next;
        }
        return dummy.next;
    }
};
