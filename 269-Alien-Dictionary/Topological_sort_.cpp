class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> edges;
        unordered_map<char, int> dependence;

        for(int i = 0; i < words[0].size(); i++){
            if(!dependence.count(words[0][i])){
                dependence[words[0][i]] = 0;
            }
        }

        for(int i = 1; i < words.size(); i++){
            parseDependence(words[i - 1], words[i], edges, dependence);

            for(int j = 0; j < words[i].size(); j++){
                if(!dependence.count(words[i][j])){
                    dependence[words[i][j]] = 0;
                }
            }
        }

        string res = "";

        int count = 0;
        queue<char> toVisit;
        for(auto it = dependence.begin(); it != dependence.end(); it++){
            if(it->second == 0){
                toVisit.push(it->first);
            }
        }

        while(!toVisit.empty()){
            char current = toVisit.front(); toVisit.pop();
            res += current;
            count++;

            for(auto it = edges[current].begin(); it != edges[current].end(); it++){
                if( (--dependence[*it]) == 0){
                    toVisit.push(*it);
                }
            }
        }

        if(count != dependence.size()){
            return "";
        }

        return res;
    }

private:
    void parseDependence(string& word1, string& word2,
            unordered_map<char, unordered_set<char>>& edges,
            unordered_map<char, int>& dependence){
        int len = min(word1.size(), word2.size());
        for(int i = 0; i < len; i++){
            if(word1[i] != word2[i]){
                if(!edges[word1[i]].count(word2[i])){
                    edges[word1[i]].insert(word2[i]);
                    dependence[word2[i]]++;
                }
                break;
            }
        }
    }
};
