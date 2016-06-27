class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto& w : dictionary) {++map[mapstr(w)]; ++map['#'+w];}
    }

    bool isUnique(string word) {
        return (map['#'+word]==map[mapstr(word)]);
    }
private:
    unordered_map<string, int> map;
    string mapstr(const string& w) {
        return (w.size()<=2) ? w : (w[0]+to_string(w.size()-2)+w[w.size()-1]);
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");