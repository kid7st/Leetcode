class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isKey = false;
        //count = 0;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    
    bool isKey;
    //int count;
    TrieNode* children[26];
};

class WordDictionary {
public:

    WordDictionary(){
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *node = root;
        for(char ch : word){
            if(node->children[ch - 'a'] == NULL){
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isKey = true;        
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root);
    }
    
    bool search(string word, TrieNode *root){
        if(root == NULL){
            return false;
        }else if(word.empty()){
            return root->isKey;
        }else if(word[0] == '.'){
            bool found = false;
            for(int i = 0; i < 25; i++){
                found = found | search(word.substr(1), root->children[i]);
                if(found) return true;
            }
        }else{
            if(root->children[word[0] - 'a'] == NULL)
                return false;
            else
                return search(word.substr(1), root->children[word[0] - 'a']);
        }
        
        return false;
    }
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");