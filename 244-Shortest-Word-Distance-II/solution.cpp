class WordDistance {
public:
    WordDistance(vector<string>& words) {
        words_size = words.size();
        for(int i = 0; i<words.size(); i++){
            if(positionMap.count(words[i]) == 0){
                vector<int> positions;
                positions.push_back(i);
                positionMap[words[i]] = positions;
            }else{
                positionMap[words[i]].push_back(i);
            }
        }
    }

    int shortest(string word1, string word2) {
        int ret = words_size;
        for(int i = 0; i<positionMap[word1].size(); i++){
            for(int j = 0; j<positionMap[word2].size(); j++){
                int current = positionMap[word1][i] - positionMap[word2][j];
                if(current < 0)
                    current = -current;
                if(current < ret)
                    ret = current;
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