class LRUCache {
public:
    LRUCache(int capacity) : _cap(capacity), _head(nullptr), _tail(nullptr) {
        
    }
    
    int get(int key) {
        if (auto it = mp.find(key); it != mp.end()) {
            Node *node = it->second;
            moveToTail(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (auto it = mp.find(key); it != mp.end()) {
            Node *node = it->second;
            node->val = value;
            moveToTail(node);
            return;
        }

        if (mp.size() == _cap) {
            mp.erase(_head->key);
            auto tmp = _head;
            _head = _head->next;
            if (_head) {
                _head->prev = nullptr;
            } else {
                _tail = nullptr;
            }
            delete tmp;
        }

        Node *newNode = new Node{key, value, nullptr, _tail};
        if (_tail) {
            _tail->next = newNode;
        } else {
            _head = newNode;
        }
        _tail = newNode;
        mp[key] = newNode;
    }
private:
    struct Node {
        int key;
        int val;
        Node *next, *prev;
    };

    void moveToTail(Node *node) {
        if (node == _tail) return;
        if (node == _head) {
            _head = node->next;
            if (_head) _head->prev = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = _tail;
        node->next = nullptr;
        _tail->next = node;
        _tail = node;
    }

    unordered_map<int, Node*> mp;
    int _cap;
    Node *_head, *_tail;
};
