class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n > 0){
            int rest = n%26;
            char ch = (rest == 0) ? 'Z' : 'A' - 1 + rest;
            
            res = string(1, ch) + res;
            n = (n / 26);
            if(rest == 0) n -= 1;
        }
        return res;
    }
};