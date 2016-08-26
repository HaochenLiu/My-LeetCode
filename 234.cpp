/*
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
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
        while(cur->next) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        
        return dummy.next;
    }
       
public:
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if(head == NULL || head->next == NULL) return true;
        int cnt = getCnt(head);
        ListNode* cur = head;

        for(int i = 0; i < (cnt - 1) / 2; i++) {
            cur = cur->next;
        }
        
        ListNode* mid = reverseList(cur->next);
        while(mid) {
            if(mid->val != head->val) {
                return false;
            }
            mid = mid->next;
            head = head->next;
        }
        return true;        
    }
};
