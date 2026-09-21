class WordDictionary {
public:
    WordDictionary() : root(new TrieNode()) {
        
    }
    
    void addWord(string word) {
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
        return searchFrom(word, root);
    }
private:
    struct TrieNode {
        array<TrieNode*, 26> children{};
        bool isEnd{};
    };

    TrieNode* root;

    static bool searchFrom(string_view sv, TrieNode* node) {
        if (!node) return false;

        if (sv.empty()) return node->isEnd;
        
        if (sv[0] == '.') {
            for (TrieNode* child : node->children) {
                if (searchFrom(sv.substr(1), child)) {
                    return true;
                }
            }
            return false;
        }

        return searchFrom(sv.substr(1), node->children[sv[0] - 'a']);
    }
};
