/*
147. Insertion Sort List

Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* prev = ins->next;
        ListNode* cur = prev->next;
        while(cur) {
            if(cur->val >= prev->val) {
                cur = cur->next;
                prev = prev->next;
            } else {
                ListNode* tmp = ins;
                while(true) {
                    if(tmp->next->val >= cur->val) {
                        ListNode* move = prev->next;
                        prev->next = cur->next;
                        cur->next = tmp->next;
                        tmp->next = move;
                        break;
                    }
                    tmp = tmp->next;
                }
                cur = prev->next;
            }
        }

        return dummy.next;
    }
};
