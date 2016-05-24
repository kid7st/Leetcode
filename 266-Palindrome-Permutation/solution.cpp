class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> mp;
        int count_1 = 0;
        
        for(int i = 0; i < s.size(); i++){
            mp[s[i]] += 1;
        }
        
        for(auto pair : mp){
            int count = pair.second;
            if(count % 2 == 1)
                count_1 += 1;
        }
        
        if(s.size() % 2 == 0){
            if(count_1 == 0){
                return true;
            }else{
                return false;
            }
        }
        
        if(s.size() % 2 == 1){
            if(count_1 == 1){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};