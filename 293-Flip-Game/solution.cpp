class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for(int i = 1; i < s.size(); i++){
            if(s[i - 1] == '+' && s[i] == '+'){
                s[i - 1] = '-';
                s[i] = '-';
                res.push_back(s);
                s[i - 1] = '+';
                s[i] = '+';
            }
        }
        
        return res;
    }
};