/*
288. Unique Word Abbreviation

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

/*
ValidWordAbbr(vector<string> &dictionary) {}
Time: O(n)
Space: O(n)
Extra space: O(n)

bool isUnique(string word) {}
Time: O(1)
Space: O(1)
Extra space: O(1)
*/

class ValidWordAbbr {
private:
    unordered_map<string, vector<string>> m;
    
    string abbr(string str) {
        if(str.size() <= 2) return str;
        string res = "";
        res.append(1, str[0]);
        res += to_string(str.size() - 2);
        res.append(1, str[str.size() - 1]);
        return res;
    }
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        int n = dictionary.size(); 
        for(int i = 0; i < n; i++) {
            m[abbr(dictionary[i])].push_back(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        vector<string> res = m[abbr(word)];
        int n = res.size();
        for(int i = 0; i < n; i++) {
            if(res[i] != word) {
                return false;
            }
        }
        return true;
    }
};

// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
