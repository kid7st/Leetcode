class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int size = log10(x);
        int max = pow(10, size);
        int offset = 1;
        for(int i = 0; i < (size + 1)/2; i++){
            if((x % (10*offset) / offset) != (x / (max / offset) % 10)) return false;
            offset *= 10;
        }
        
        return true;
    }
};