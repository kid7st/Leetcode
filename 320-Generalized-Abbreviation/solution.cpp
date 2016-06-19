class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        res.push_back(word);
        dfs(word, 0, res);
        return res;
    }
    
    void dfs(string word, int start, vector<string>& acc){
        for(int len = 1; len <= word.size() - start; len++){
            for(int i = start; i + len <= word.size(); i++){
                string abbr = word;
                abbr.replace(i, len, to_string(len));
                acc.push_back(abbr);
                int pos = abbr.find_last_of(to_string(len));
                if(pos + 2 < abbr.size()){
                    dfs(abbr, pos + 2, acc);
                }
            }
        }
    }
};