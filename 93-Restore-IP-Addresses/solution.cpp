class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, 1, res);
        return res;
    }
    
    void dfs(string s, int start, int k, vector<string> &acc){
        if(k == 4){
            if(start >= s.size()) return;
            if(s.size() - start > 3) return;
            string word = s.substr(start);
            if(word[0] == '0' && word.size() > 1) return;
            
            int num = stoi(word);
            if(num <= 255){
                acc.push_back(s);
                return;
            }
            
        }
        
        for(int i = 1; i <= 3; i++){
            if(start + i > s.size()) return;
            string word = s.substr(start, i);
            if(word.size() > 1 && word[0] == '0')
                return;
            
            int num = stoi(word);
            if(num <= 255){
                string newS = s.substr(0, start + i) + string(1, '.') + s.substr(start + i);
                dfs(newS, start + i + 1, k + 1, acc);
            }
        }
    }
};