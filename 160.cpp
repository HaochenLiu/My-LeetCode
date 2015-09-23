/*
160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3


begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int cntA = getCnt(headA);
        int cntB = getCnt(headB);

        if(cntA > cntB) {
            for(int i = 0; i < cntA - cntB; i++) {
                headA = headA->next;
            }
        }

        if(cntB > cntA) {
            for(int i = 0; i < cntB - cntA; i++) {
                headB = headB->next;
            }
        }
        
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};
