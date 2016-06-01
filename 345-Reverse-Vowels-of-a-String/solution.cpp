class Solution {
public:
    string reverseVowels(string s) {
        int slen = s.length();
        for (int l = 0, r = slen - 1; l < r; ++l){
            if (isVowel(s[l])){
                while ((l < r) && !isVowel(s[r]) )
                    --r;

                swap(s[l], s[r--]);
            }
        }
        return s;
    }
    
private:
    bool isVowel(char c){
        return (c == 'a') || (c == 'e') || (c == 'o') || (c == 'i') || (c == 'u') ||
           (c == 'A') || (c == 'E') || (c == 'O') || (c == 'I') || (c == 'U') ;
    }
};