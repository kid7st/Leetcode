class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while(end >= 0 && s[end] == ' ')
            end--;
        for(int i = end; i >= 0; i--){
            if(s[i] == ' ' && s[i + 1] != ' '){
                return end - i;
            }
            
            if(i == 0 && s[i] != ' '){
                return end - i + 1;
            }
        }
        
        return 0;
    }
};