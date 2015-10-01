/*
088. Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

/*
Time: O(mn)
Space: O(1)
Extra space: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            for(int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }
        if(n == 0) return;

        int idx1 = 0;
        int idx2 = 0;
        while(idx2 < n) {
            if(idx1 == m) {
                nums1.insert(nums1.begin() + m + idx2, nums2[idx2]);
                idx2++;
                continue;
            }

            if(nums1[idx1 + idx2] < nums2[idx2]) {
                idx1++;
            } else {
                nums1.insert(nums1.begin() + idx1 + idx2, nums2[idx2]);
                idx2++;
            }
        }

        nums1.erase(nums1.begin() + m + n, nums1.end());
        return;
    }
};
