/*
364. Nested List Weight Sum II

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    void DFS(vector<NestedInteger>& nestedList, int depth)
    {
        maxDepth = max(maxDepth, depth);
        for(auto val: nestedList)
        {
            if(!val.isInteger()) DFS(val.getList(), depth+1); 
            else nums.push_back(make_pair(val.getInteger(), depth));
        }
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if(nestedList.size() ==0) return 0;
        DFS(nestedList, 1);
        for(auto val: nums) result+= (maxDepth-val.second+1)*val.first;
        return result;
    }
private:
    vector<pair<int, int>> nums;
    int maxDepth = 0, result = 0;
};
