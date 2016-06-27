class Solution {
public:
    int romanToInt(string s) {
        int ans = chToInt(s[s.size() - 1]);
        for(int i = s.size() - 2; i >= 0; i--){
            if(chToInt(s[i]) < chToInt(s[i + 1])){
                ans -= chToInt(s[i]);
            }else{
                ans += chToInt(s[i]);
            }
        }
        return ans;
    }
private:
    int chToInt(char ch){
        if(ch == 'I') return 1;
        if(ch == 'V') return 5;
        if(ch == 'X') return 10;
        if(ch == 'L') return 50;
        if(ch == 'C') return 100;
        if(ch == 'D') return 500;
        if(ch == 'M') return 1000;
        return 0;
    }
};