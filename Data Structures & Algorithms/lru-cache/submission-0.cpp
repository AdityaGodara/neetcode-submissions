class LRUCache {

struct ListNode{
    int key;
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int k, int v){
        key = k;
        val = v;
        next = prev = NULL;
    }
};

public:

    ListNode* head = new ListNode(-1,-1);
    ListNode* tail = new ListNode(-1,-1);

    unordered_map<int, ListNode*> m;
    int limit;

    void addNode(ListNode* node){
        ListNode* oldNode = head->next;
        head->next = node;
        oldNode->prev = node;

        node->next = oldNode;
        node->prev = head;
    }

    void delNode(ListNode* node){
        ListNode* oldPrev = node->prev;
        ListNode* oldNext = node->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        ListNode* newNode = new ListNode(key, m[key]->val);
        addNode(newNode);
        delNode(m[key]);
        m[key] = newNode;
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            ListNode* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if(m.size() == limit){
            //DELETE LRU
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        ListNode* newNode = new ListNode(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};
