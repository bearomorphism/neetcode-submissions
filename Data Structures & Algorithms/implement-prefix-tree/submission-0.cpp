class PrefixTree {
public:
    PrefixTree() : root(new TrieNode()) {
        
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) {
                return false;
            }
            cur = cur->children[i];
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!cur->children[i]) {
                return false;
            }
            cur = cur->children[i];
        }

        return true;
    }
private:
    struct TrieNode {
        bool isEnd{};
        array<TrieNode*, 26> children{};
    };

    TrieNode* root;
};
