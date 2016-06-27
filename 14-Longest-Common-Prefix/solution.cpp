class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = "";
        int len = 1;
        bool flag = true;
        while(flag){
            if(strs[0].size() < len) break;
            string tryPrefix = strs[0].substr(0, len);
            for(string str : strs){
                if(str.size() < len){
                    flag = false;
                    break;
                }
                if(tryPrefix != str.substr(0, len)){
                    flag = false;
                    break;
                }
            }
            if(flag) prefix = tryPrefix;
            len++;
        }
        return prefix;
    }
};