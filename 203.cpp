/*
203. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* cur = &dummy;
        ListNode* tmp = cur->next;

        while(cur->next) {
            if(tmp->val != val) {
                cur = cur->next;
                tmp = cur->next;
            } else {
                ListNode* del = cur->next;
                cur->next = cur->next->next;
                delete(del);
                tmp = cur->next;
            }
        }

        return dummy.next;
    }
};
