class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMpt;
        unordered_map<char, char> tMps;
        for(int i = 0; i < s.size(); i++){
            if(sMpt[s[i]] == 0 && tMps[t[i]] == 0){
                sMpt[s[i]] = t[i];
                tMps[t[i]] = s[i];
            }else{
                if(sMpt[s[i]] != t[i] || tMps[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};