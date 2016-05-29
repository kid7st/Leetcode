class Solution {
public:
    bool isPalindrome(string s) {
        auto begin = s.begin();
        auto end = s.end() - 1;
        
        while(begin < end){
            while(begin <= end && !isAlphanumeric(*begin))
                begin++;
            while(begin <= end && !isAlphanumeric(*end))
                end--;
                
            if(begin <= end &&  toupper(*begin) != toupper(*end))
                return false;
                
            begin++;
            end--;
        }
        return true;
    }
    
private:
    bool isAlphanumeric(char ch){
        if(ch >= 48 && ch <= 57)
            return true;
        if(ch >= 65 && ch <= 90)
            return true;
        if(ch >= 97 && ch <= 122)
            return true;
            
        return false;
    }
};