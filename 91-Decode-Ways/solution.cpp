class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        
        vector<int> dp(s.size(), 0);
        if((s[0] - '0') >= 1){
            dp[0] = 1;
        }else{
            dp[0] = 0;
        }
        if(s.size() == 1)
            return dp[0];
        
        if((s[1] - '0') >= 1){
            dp[1] = dp[0];
        }
            
        if((s[0] - '0') >= 1){
            int code = atoi(s.substr(0, 2).c_str());
            if(code >= 1 && code <= 26){
                dp[1] += 1;
            }
        }
            
        for(int i = 2; i < s.size(); i++){
            if((s[i] - '0') >= 1){
                dp[i] = dp[i - 1];
            }
            
            if((s[i - 1] - '0') >= 1){
                int code = atoi(s.substr(i - 1, 2).c_str());
                if(code >= 1 && code <= 26){
                    dp[i] += dp[i - 2];
                }
            }
            
            if(dp[i] == 0 && dp[i - 1] == 0) return 0;
        }
        
        return dp[s.size() - 1];
    }
};