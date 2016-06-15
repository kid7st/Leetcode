class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> acc;
        dfs(s, acc, res);
        return res;
    }
    
private:
    void dfs(string s, vector<string> &acc, vector<vector<string>> &res){
        if(s.empty()){
            res.push_back(acc);
            return;
        }
        
        for(int i = 1; i <= s.size(); i++){
            string head = s.substr(0, i);
            if(isPalindrome(head)){
                acc.push_back(head);
                dfs(s.substr(i), acc, res);
                acc.pop_back();
            }
        }
        
        return;
    }
    
    bool isPalindrome(string s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }
};