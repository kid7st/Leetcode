class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", n, n, res);
        return res;
    }
    
    void dfs(string s, int l, int r, vector<string> &acc){
        if(r == 0){
            acc.push_back(s);
        }else if(l == 0){
            dfs(s + ')', l, r - 1, acc);
        }else{
            if(r > l){
                dfs(s + ')', l, r - 1, acc);
            }
            dfs(s + '(', l - 1, r, acc);
        }
    }
};