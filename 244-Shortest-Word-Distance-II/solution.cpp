class WordDistance {
public:
    WordDistance(vector<string>& words) {
        words_size = words.size();
        for(int i = 0; i<words.size(); i++){
            positionMap[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int ret = words_size;
        for(int i = 0; i<positionMap[word1].size(); i++){
            for(int j = 0; j<positionMap[word2].size(); j++){
                int current = abs(positionMap[word1][i] - positionMap[word2][j]);
                ret = min(ret, current);
            }
        }
        return ret;
    }
    
private:
    int words_size;
    unordered_map<string, vector<int>> positionMap;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");