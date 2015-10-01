/*
061. Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
private:
    int getCnt(ListNode* node) {
        int res = 0;
        while(node) {
            node = node->next;
            res++;
        }

        return res;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k < 1) return head;
        int cnt = getCnt(head);

        ListNode* node = head;
        ListNode* tail = head;
        while(node != NULL){
            tail = node;
            node = node->next;
        }
        
        k %= cnt;
        if(k == 0) return head;
        
        int left = cnt - k;
        node = head;
        for(int i = 0; i < left - 1; ++i) {
            node = node->next;
        }

        ListNode* newTail = node;
        ListNode* newHead = node->next;
        newTail->next = NULL;
        tail->next = head;
        return newHead;
    }
};
