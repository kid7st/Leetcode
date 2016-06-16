class Solution {
public:
    bool canWin(string s) {
        if(s.size() < 2) return false;
        
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '+' && s[i + 1] == '+'){
                s[i] = '-'; s[i + 1] = '-';
                if(!canWin(s)) return true;
                s[i] = '+'; s[i + 1] = '+';
            }
        }
        return false;
    }
};