/*
Hashtable and DP or two-pointers
Time O(n)
Space O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
            
        vector<int> lastIndex(256, -1);
        int maxLength = 1;
        
        int j = 0;
        lastIndex[s[0]] = 0;
        for(int i = 1; i < s.size(); i++){
            if(lastIndex[s[i]] >= j){
                j = lastIndex[s[i]] += 1;
            }
            lastIndex[s[i]] = i;
            
            maxLength = max(i - j + 1, maxLength);
        }
        
        return maxLength;
    }
};