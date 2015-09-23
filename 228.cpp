/*
228. Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> result;
        if(len == 0){
            return result;
        }
        int left = nums[0];
        nums.push_back(nums[len-1]);
        len++;
        for(int i=1; i<len; i++){
            if(nums[i] == nums[i-1] || ((long long)nums[i] - (long long)nums[i-1] > 1)){
                if(left == nums[i-1]){
                    result.push_back(intToString(left));
                }else{
                    result.push_back(intToString(left) + "->" + intToString(nums[i-1]));
                }
                left = nums[i];
            }
        }
        return result;
    }
    
    string intToString(int n){
        if(n==0){
            return "0";
        }
        long long lN = n;
        string s = "";
        if(lN<0){
            s = "-";
            lN = -lN;
        }
        stack<char> stacks;
        while(lN!=0){
            stacks.push(lN%10 + '0');
            lN = lN/10;
        }
        while(!stacks.empty()){
            s += stacks.top();
            stacks.pop();
        }
        return s;
    }
};
