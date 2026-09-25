/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp; // original -> new

        Node* dummy = new Node(0);
        Node* cur = head;
        Node* newCur = dummy;
        while (cur) {
            Node* newNode = new Node(cur->val);
            mp[cur] = newCur->next = newNode;

            cur = cur->next;
            newCur = newCur->next;
        }

        cur = head;
        newCur = dummy;
        while (cur) {
            Node *r = cur->random;
            newCur->next->random = r ? mp[r] : nullptr;
        
            cur = cur->next;
            newCur = newCur->next;
        }
        
        return dummy->next;
    }
};
