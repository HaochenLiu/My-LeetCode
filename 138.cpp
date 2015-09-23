/*
138. Copy List with Random Pointer
http://www.cnblogs.com/easonliu/p/3647160.html

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        if(head == NULL) return NULL;
        RandomListNode* pos1 = head;
        RandomListNode* pos2 = head->next;
        while (pos1 != NULL) {
            pos1->next = new RandomListNode(pos1->label);
            pos1->next->next = pos2;
            pos1 = pos2;
            if (pos2 != NULL) {
                pos2 = pos2->next;
            }
        }
        pos1 = head;
        pos2 = head->next;
        while(pos1 != NULL) {
            if(pos1->random == NULL) {
                pos2->random = NULL;
            } else {
                pos2->random = pos1->random->next;
            }
            pos1 = pos1->next->next;
            if(pos2->next != NULL)
                pos2 = pos2->next->next;
        }
        RandomListNode* res = head->next;
        pos1 = head;
        pos2 = head->next;
        while(pos2->next != NULL) {
            pos1->next = pos2->next;
            pos1 = pos2;
            if(pos2->next != NULL) {
                pos2 = pos2->next;
            }
        }
        pos1->next = NULL;
        pos2->next = NULL;

        return res;
    }
};
