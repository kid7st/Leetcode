/*
 * DP state:
 *  dp[i][j] -- if s[0 ~ (i-1)] match p[0 ~ (j-1)] or not
 *
 *  dp[i][j] = 
        (1) p[j-1] != '*' && p[j-1] != '.': match the current s[i-1] == p[j-1], so dp[i][j] = (i > 0) && (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
        (2) p[j-1] == '.': match s[i-1] with any charactor, then dp[i][j] = (i > 0) && dp[i - 1][j - 1];
        (3) p[j-1] == '*':the preceding matchs 0 charactor or 1 charactors: dp[i][j] = dp[i][j] || dp[i][j - 2] || dp[i][j - 1];
                            the preceding matchs one more charactors:
                                dp[i][j] = dp[i][j] || ( (i > 0) && ( (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j] ) );
 
 * Time complexity: O(N*M);
 * Space complexity: O(N*M);
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        
        vector< vector<bool> > dp(len_s + 1, vector<bool>(len_p + 1, false));
        dp[0][0] = true;
        
        for(int i = 0; i <= len_s; i++){
            for(int j = 1; j <= len_p ; j++){
                if(p[j-1] != '*'){
                    if(p[j-1] != '.')
                        dp[i][j] = (i > 0) && (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                    else
                        dp[i][j] = (i > 0) && dp[i - 1][j - 1];
                }else if(j > 1){
                    // * can't be the first charactor
                    
                    //match none or 1 charactor
                    dp[i][j] = dp[i][j] || dp[i][j - 2] || dp[i][j - 1];
                    
                    //match 1 more charactors
                    dp[i][j] = dp[i][j] || ( (i > 0) && ( (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j] ) );
                }
            }
        }
        
        return dp[len_s][len_p];
    }
};