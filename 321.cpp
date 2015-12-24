/*
321. Create Maximum Number

Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:

nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:

nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:

nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int size1 = nums1.size();
        const int size2 = nums2.size();
        if (size1 + size2 < k) return vector<int>();
        vector<int> res(k, 0);
        vector<vector<int>> dp1(k+1, vector<int>()), dp2(k+1, vector<int>());
        getDp(nums1, k, dp1);
        getDp(nums2, k, dp2);
        for (int i = 0; i <= min(k, size1); i++) {
            int j = k - i;
            vector<int> temp_res(k, 0);
            myMerge(dp1[i].begin(), dp1[i].end(), dp2[j].begin(), dp2[j].end(), temp_res.begin());
            if (j <= size2 && compareVector(temp_res, res)) {
                res = temp_res;
            }
        }
        return res;
    }
    
    template <class container>
    bool compareVector ( container vec1, container vec2)
    {
      typename container::iterator first1 = vec1.begin(), last1 = vec1.end();
      typename container::iterator first2 = vec2.begin(), last2 = vec2.end();
      while (first1 != last1 && first2 != last2) {
        if (*first1 > *first2)
          return true;
        else if (*first1 < *first2) return false;
        ++first1; ++first2;
      }
      if (first1 == last1) return false;
      else return true;
    }
    
    void getDp(vector<int> nums, int k, vector<vector<int>> &dp) 
    {
          while (nums.size() > k) {
                int j = 0;
                for (; j < nums.size() - 1; ++j) {
                    if (nums[j] < nums[j + 1]) {
                        nums.erase(nums.begin() + j); 
                        break;
                    }
                }
                if (j == nums.size() - 1) nums.erase(nums.begin() + j); 
           }
           dp[nums.size()] = nums;
           const int size1 = nums.size();
           for (int i = k; i > 0; i--) {
            if (i >= size1) continue; 
            else {
                dp[i] = dp[i+1];
                int j = 0;
                const int size_dp = dp[i].size();
                for (; j < size_dp - 1; ++j) {
                    if (dp[i][j] < dp[i][j + 1]) {
                        dp[i].erase(dp[i].begin() + j); 
                        break;
                    }
                }
                if (j == size_dp - 1) dp[i].erase(dp[i].begin() + j); 
            }
    
        }
    }

    template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator myMerge (InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2,
                        OutputIterator result)
    {
        while (true) {
            if (first1==last1) return std::copy(first2,last2,result);
            if (first2==last2) return std::copy(first1,last1,result);
            if (*first2 > *first1) {
                *result++ = *first2++;
            } else if (*first2 < *first1) {
                *result++ = *first1++;
            } else { // *first1 == *first2
                auto pos1 = first1, pos2 = first2;
                while (true) {
                    int f1 = (++pos1 != last1) ? *(pos1) : INT_MIN;
                    int f2 = (++pos2 != last2) ? *(pos2) : INT_MIN;
                    if (f1 > f2) {
                        *result++ = *first1++; 
                        break;
                    } else if (f1 < f2) {
                        *result++ = *first2++;
                        break;
                    }
                }
            }
        }
    }
};
