class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res = {""};
        for(char d : digits){
            vector<string> next;
            for(string& s : res){
                for(char letter : m[d-'0']){
                    next.push_back(s+letter);
                }
            }
            res = next;
        }
        return res;
    }
};