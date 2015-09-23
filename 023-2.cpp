/*
023. Merge k Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MyCompare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; //大于！
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MyCompare> q;
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i]) {
                q.push(lists[i]);
            }
        }
        
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            cur->next = node;
            cur = cur->next;
            if(node->next) {
                q.push(node->next);
            }
        }
        return dummy.next;
    }
};
