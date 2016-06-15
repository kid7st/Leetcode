class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        
        if(digits.size() == 1){
            vector<string> res;
            for(char letter : digitalMap[digits[0]]){
                res.push_back(string(1, letter));
            }
            return res;
        }
        
        vector<string> res;
        vector<string> restStr = letterCombinations(digits.substr(0, digits.size() - 1));
        for(char letter : digitalMap[ digits[digits.size() - 1] ]){
            for(string str : restStr){
                str.push_back(letter);
                res.push_back(str);
            }
        }
        
        return res;
    }
    
private:
    unordered_map<char, string> digitalMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
};