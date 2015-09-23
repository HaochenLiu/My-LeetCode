/*
165. Compare Version Numbers

Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    vector<int> v1, v2;
    int splitVersion(const char* str, vector<int> &v) {
        v.clear();
        char* buf = new char[strlen(str) + 1];
        strcpy(buf, str);
        char* p = strtok(buf, ".");
        while(p) {
            v.push_back(atoi(p));
            p = strtok(NULL, ".");
        }
        delete[] buf;
    }
    
    int compareVersion(string version1, string version2) {
        const char* str1 = version1.c_str();
        const char* str2 = version2.c_str();
        splitVersion(str1, v1);
        splitVersion(str2, v2);
        
        while(v1.size() != 0 && v1[v1.size() - 1] == 0) {
            v1.pop_back();
        }

        while(v2.size() != 0 && v2[v2.size() - 1] == 0) {
            v2.pop_back();
        }
        
        int n = min(v1.size(), v2.size());
        for(int i = 0; i < n; i++) {
            if(v1[i] > v2[i]) {
                return 1;
            } else if(v1[i] < v2[i]) {
                return -1;
            } else {
                continue;
            }
        }
        
        if(v1.size() > v2.size()) {
            return 1;
        } else if(v1.size() < v2.size()) {
            return -1;
        } else {
            return 0;
        }
    }
};
