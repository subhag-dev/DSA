class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    
    TrieNode() {
        isEnd = false;
        children = vector<TrieNode*> (26, NULL);
    }   
};

class Trie {
public:
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (auto alphabet: word) {
            if (curr -> children[alphabet - 'a'] == NULL) {
                curr -> children[alphabet - 'a'] = new TrieNode();
            }   
            curr = curr -> children[alphabet - 'a'];
        }
        curr -> isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (auto alphabet: word) {
            if (curr -> children[alphabet - 'a'] == NULL) return false;
            curr = curr -> children[alphabet - 'a'];
        }
        return curr -> isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto alphabet: prefix) {
            if (curr -> children[alphabet - 'a'] == NULL) return false;
            curr = curr -> children[alphabet - 'a'];
        }
        return true;
    }
};
