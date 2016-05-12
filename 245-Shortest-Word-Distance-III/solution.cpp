class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        vector<int> pos1;
        vector<int> pos2;
        
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1)
                pos1.push_back(i);
            if(words[i] == word2)
                pos2.push_back(i);
        }
        
        int ret = words.size();
        for(int i = 0; i < pos1.size(); i++){
            for(int j = 0; j < pos2.size(); j++){
                if(pos1 - pos2 != 0){
                    int current = pos1 - pos2;
                    if(current < 0)
                        current = -current;
                    if(current < ret)
                        ret = current;
                }
            }
        }
        
        return ret;
    }
};