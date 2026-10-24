class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;
            Node(int key,int val){
                this -> key = key;
                this -> val = val;
            }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*>m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newNode){
        Node* temp = head -> next;
        head -> next = newNode;
        newNode -> prev = head;
        temp -> prev = newNode;
        newNode -> next = temp;
    }


    void delNode(Node* node){
        Node* pre = node -> prev;
        Node* next = node -> next;
        pre -> next = next;
        next -> prev = pre;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            int ans = node -> val;

            m.erase(key);
            delNode(node);
            addNode(node);

            m[key] = node;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            m.erase(key);
            delNode(node);
        }

        if(cap == m.size()){
            m.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */