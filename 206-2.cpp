/*
206. Reverse Linked List

Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* tmp = head;
        while(tmp) {
            st.push(tmp->val);
            tmp = tmp->next;
        }
        
        tmp = head;
        while(!st.empty()) {
            tmp->val = st.top();
            st.pop();
            tmp = tmp->next;
        }
        return head;
    }
};
