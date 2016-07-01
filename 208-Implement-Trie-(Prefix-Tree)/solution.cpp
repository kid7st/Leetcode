class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isKey = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    
    bool isKey;
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *node = root;
        for(char ch : word){
            if(node->children[ch - 'a'] == NULL){
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isKey = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = root;
        for(char ch : word){
            if(node->children[ch - 'a'] == NULL) return false;
            node = node->children[ch - 'a'];
        }
        return node->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(char ch : prefix){
            if(node->children[ch - 'a'] == NULL) return false;
            node = node->children[ch - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");