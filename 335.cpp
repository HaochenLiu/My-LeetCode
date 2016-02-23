/*
335. Self Crossing

You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:
Given x = [2, 1, 1, 2]
Return true (self crossing)
Example 2:
Given x = [1, 2, 3, 4]
Return false (not self crossing)
Example 3:
Given x = [1, 1, 1, 1]
Return true (self crossing)
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() < 4) return false;
        for (auto it = x.begin() + 3; it != x.end(); ++it)
        {

            if (*(it - 1) <= *(it - 3))
            { // in
                if (*it >= *(it - 2))
                    return true;
                ++it;
                while (it != x.end())
                {
                    if (*it >= *(it - 2)) return true;
                    ++it;
                }
                return false;
            }
            else
            { // out
                if (*it <= *(it - 2))
                {// in
                    ++it;


                    if (it != x.end() && it - 4 >= x.begin())
                    {
                        if (*(it - 1) == *(it - 3) && *(it - 2) <= *it + *(it - 4))
                            return true;
                        if (it - 5 >= x.begin())
                        {
                            if (*(it - 3) <= *(it - 5) + *(it - 1) &&
                                *(it - 4) + *it >= *(it - 2))
                                return true;
                        }

                    }
                    while (it != x.end())
                    {
                        if (*it >= *(it - 2)) return true;
                        ++it;
                    }

                    return false;
                }
            }
        }

        return false;
    }
};
