/*
282. Expression Add Operators

Given a string that contains only digits 0-9 and a target value, return all possibilities to add operators +, -, or * between the digits so they evaluate to the target value.
Examples:
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []


Credits:
Special thanks to @davidtan1890 for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool cal(string &e, int &target, int pos, int pre_val, int cur_val, string tmp_e, vector<string> &ret) {
        // Base Case 1
        if (pos == e.length()) {
            if (pre_val + cur_val == target) {
                ret.push_back(tmp_e);
                return true;
            }
            return false;
        }
        int tmp_val = 0;
        string tmp = "";
        int pre_val2, cur_val2;
        string tmp_e2;
        for (int i = pos; i < e.length(); i ++) {
            tmp_val = tmp_val * 10 + e[i] - '0';
            tmp += e[i];
            if (tmp.size() == to_string(INT_MAX).size() && tmp > to_string(INT_MAX))
                break;
            // Case 1: '+'
            pre_val2 = pre_val + cur_val;
            if (tmp_e.length() == 0) {
                tmp_e2 = tmp;
            } else {
                tmp_e2 = tmp_e + '+' + tmp;
            }
            cal(e, target, i + 1, pre_val2, tmp_val, tmp_e2, ret);
    
            if (tmp_e.length() == 0) {
                if (tmp_val == 0)
                    break;
                continue;
            }
    
            // Case 2: '-'
            pre_val2 = pre_val + cur_val;
            if (tmp_e.length() == 0) {
                tmp_e2 = tmp;
            } else {
                tmp_e2 = tmp_e + '-' + tmp;
            }
            cal(e, target, i + 1, pre_val2, -tmp_val, tmp_e2, ret);
    
            // Case 3: '*'
            cur_val2 = cur_val * tmp_val;
            tmp_e2 = tmp_e + '*' + tmp;
            cal(e, target, i + 1, pre_val, cur_val2, tmp_e2, ret);
    
            // char is '0'
            if (tmp_val == 0)
                break;
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        cal(num, target, 0, 0, 0, "", ret);
        return ret;
    }
};
