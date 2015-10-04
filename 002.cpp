/*
002. Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
*/

/*
Time: O(n)
Space: O(n)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int carry = 0;
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(l1 || l2 || carry) {
            if(l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            cur = cur->next;
        }

        return dummy.next;
    }
};
