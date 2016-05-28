class Solution {
public:
    string reverseString(string s) {
        for(auto begin = s.begin(), end = s.end() - 1; begin < end; begin++, end--){
            char tmp = *begin;
            *begin = *end;
            *end = tmp;
        }
        
        return s;
    }
};