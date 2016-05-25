class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream sm(str);
        vector<string> words;
        string word;
        while(sm>>word){
            words.push_back(word);
        }
        
        if(words.size() != pattern.size())
            return false;
            
        unordered_map<char, string> mpCharToStr;
        unordered_map<string, char> mpStrToChar;
        
        for(int i = 0; i < pattern.size(); i++){
            if(mpCharToStr[pattern[i]] == "" && mpStrToChar[words[i]] == 0){
                mpCharToStr[pattern[i]] = words[i];
                mpStrToChar[words[i]] = pattern[i];
            }else{
                if(mpCharToStr[pattern[i]] != words[i] || mpStrToChar[words[i]] != pattern[i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};