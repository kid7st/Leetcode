class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(haystack.empty()) return -1;
        
        vector<int> preIter(needle.size(), 0);
        int k = 0;
        for(int i = 1; i < needle.size(); i++){
            while(k > 0 && needle[k] != needle[i])
                k = preIter[k - 1];
            if(needle[k] == needle[i])
                preIter[i] = ++k;
        }
        
        k = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(k > 0 && needle[k] != haystack[i])
                k = preIter[k - 1];
            if(needle[k] == haystack[i])
                k++;
            if(k == needle.size())
                return i - needle.size() + 1;
        }
        
        return -1;
    }
};