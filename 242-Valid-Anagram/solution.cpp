class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mpS(128, 0);
        vector<int> mpT(128, 0);
        
        for(char ch : s)
            mpS[ch] += 1;
        for(char ch : t)
            mpT[ch] += 1;
        
        for(int i = 0; i < 128; i++){
            if(mpS[i] != mpT[i])
                return false;
        }
        
        return true;
    }
};