/*
023. Merge k Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

/*
Time: O(n*logk)
Space: O(logk)
n is number of nodes
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* proot = NULL;
        ListNode** pplast = &proot;
        while(l1 || l2){
            if(l1) {
                ListNode* minNode;
                if(!l2 || l1->val <= l2->val){
                    //l1 is min
                    minNode = l1;
                    l1 = l1->next;
                } else if(l2) {
                    //l2 is min
                    minNode = l2;
                    l2 = l2->next;
                }
                //proceed root
                *pplast = minNode;
                pplast = &(minNode->next);
            } else {
                //l1 is empty
                *pplast = l2;
                break;
            }
        }
        return proot;
    }
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if(lists.size() == 0)
            return NULL;
        int curSize = lists.size();
        while(curSize > 1) {
            int halfSize = (1 + curSize) / 2;
            //merge i,i + halfSize
            for(int i = 0 ; i < halfSize && i + halfSize < curSize; ++i) {
                ListNode* first = lists[i];
                ListNode* second = lists[i + halfSize];
                ListNode* result = mergeTwoLists(first,second);
                lists[i] = result;
            }
            //set curSize to halfsize
            curSize = halfSize;
        }
        return lists[0];
    }
};
