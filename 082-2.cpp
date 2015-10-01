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
        ListNode* cur = &dummy;
        bool flag = false;
        int val = 0;
        
        while(cur && cur->next) {
            ListNode* next = cur->next;
            if(flag) {
                if(next->val == val) {
                    cur->next = next->next;
                    delete(next);
                    continue;
                }
            }

            if(next->next == NULL) {
                break;
            }
            flag = false;

            ListNode* next2 = next->next;
            if(next->val == next2->val) {
                flag = true;
                val = next->val;
                cur->next = next2->next;
                delete(next);
                delete(next2);
                continue;
            }
            cur = cur->next;
        }
        
        return dummy.next;
    }
};
