/*
082. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        ListNode dummy(0);  
        dummy.next = head;  
        ListNode* ins = &dummy;
        ListNode* cur = head;  
        while(cur != NULL) {
            bool isDup = false;  
            while(cur->next != NULL && cur->val == cur->next->val) {  
                isDup = true;
                ListNode* temp = cur;
                cur = cur->next;
                delete temp;
            }  

            if(isDup) {
                ListNode* temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }  

            ins->next = cur;
            ins = ins->next;
            cur = cur->next;
        }  
        ins->next = cur;

        return dummy.next;
    }  
};
