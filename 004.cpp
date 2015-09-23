/*
004. Median of Two Sorted Arrays
O(log(m+n))

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    int kth(vector<int> nums1, vector<int> nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 == 0) {
            return nums2[k];
        }
        
        if(n2 == 0) {
            return nums1[k];
        }

        if(n1 / 2 + n2 / 2 < k) {
            if(nums1[n1 / 2] > nums2[n2 / 2]) {
                nums2.erase(nums2.begin(), nums2.begin() + n2 / 2 + 1);
                return kth(nums1, nums2, k - n2 / 2 - 1);
            } else {
                nums1.erase(nums1.begin(), nums1.begin() + n1 / 2 + 1);
                return kth(nums1, nums2, k - n1 / 2 - 1);
            }
        } else {
            if(nums1[n1 / 2] > nums2[n2 / 2]) {
                nums1.erase(nums1.end() - (n1 - n1 / 2), nums1.end());
                return kth(nums1, nums2, k);
            } else {
                nums2.erase(nums2.end() - (n2 - n2 / 2), nums2.end());
                return kth(nums1, nums2, k);
            }
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if(n % 2 == 1) {
            return kth(nums1, nums2, n / 2);
        } else {
            return (kth(nums1, nums2, n / 2 - 1) + kth(nums1, nums2, n / 2)) / 2.0;
        }
    }
};
