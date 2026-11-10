class Solution {
public:
    string decodeString(string s) {
        string cur = "";
        int k = 0;
        stack <int> numStack;
        stack <string> strStack;
        for(char ch : s){
            if(isdigit(ch)) {
                k = k*10 + (ch - '0');
            }
            else if (ch == '[') {
                strStack.push(cur);
                numStack.push(k);
                cur = "";
                k = 0;
            }
            else if (ch == ']') {
                string prev = strStack.top(); strStack.pop();
                int times = numStack.top(); numStack.pop();
                string repeated = "";
                for(int i = 0; i < times; i++) repeated += cur;
                cur = prev + repeated;
            }
            else {
                cur += ch;
            }
        }
        return cur;
    }
};