/*
143. Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while(cur->next != NULL) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        return dummy.next;
    }
    
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        int cnt = getCnt(head);
        ListNode* cur = head;

        for(int i = 0; i < (cnt - 1) / 2; i++) {
            cur = cur->next;
        }
        
        ListNode* mid = cur->next;
        cur->next = NULL;
        mid = reverseList(mid);
        ListNode* start = head;
        
        while(mid) {
            ListNode* tmp1 = start->next;
            ListNode* tmp2 = mid->next;
            start->next = mid;
            mid->next = tmp1;
            start = tmp1;
            mid = tmp2;
        }
        
        return;
    }
};
