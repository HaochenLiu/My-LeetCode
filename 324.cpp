/*
324. Wiggle Sort II

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Only four Line
        if (2>(n = nums.size())) return;
        r_start = n/2;
        dfs(nums, find_medin(nums));
        re_order(nums);
    }
private:
    int n;
    int r_start;
        int pivot(vector<int> &nums, int i, int j) {
        assert(i<j);
        swap(nums[i],nums[(i+j)/2]);
        int idx = i++;
        int val = nums[idx];
        while (i<j) {
            if (nums[i]<=val) i++;
            else if (nums[j]>=val) j--;
            else swap(nums[i],nums[j]);
        }
        if (nums[i]>val) i--;
        if (nums[i] != nums[idx]) swap(nums[i], nums[idx]);
        return i;
    }

    double find_kth(vector<int> &nums, int k) {
        int i = 0, j = n-1;
        while (i<j) {
            int m = pivot(nums,i,j);
            int len = m-i+1;
            if (k<len) {
                j = m-1;
            } else if (k>len) {
                k-=len;
                i = m+1;
            } else {
                return nums[m];
            }
        }
        return nums[i];
    }

    double find_medin(vector<int> &nums) {
        if (n&1) {
            return find_kth(nums, 1+(n>>1));
        } else {
            return (find_kth(nums,n>>1) + find_kth(nums, 1+(n>>1)))/2;
        }
    }

    //Dutch Flag Srot (reversed order)
    void dfs(vector<int> &nums, double target) {
        int i = 0, j = n-1, k = 0;
        while (k<=j) {
            if (nums[k]>target) {
                swap(nums[i++], nums[k++]);
            } else if (nums[k] < target) {
                swap(nums[j--], nums[k]);
            } else {
                k++;
            }
        }
    }

    int get_next(int i) {
        if (i>=r_start) return (i-r_start)<<1;
        else return 1+(i<<1);
    }
    // giving up to think a legitimate O(1) space solution.
    // cheat by using a mask to show whether it has 
    // been visited or not. This sub-problem is much harder compare
    // to array rotation, I cannot use a count and increase
    // the start by one whenever count < limit.
    void re_order(vector<int> & nums) {
        for (int mask = 1<<30, i, temp, start=0; start<n; ++start) {
            if (!(nums[start] & mask)) {
                temp = nums[i = start];
                do {swap(temp|=mask, nums[i=get_next(i)]);} while (i!=start);
            }
            nums[start] ^= mask;
        }
    }
};
