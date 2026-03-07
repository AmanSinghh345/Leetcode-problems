class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k,int v)
        {
            key=k;
            val=v;
        }
};
class LRUCache {
public:
    unordered_map<int,Node* > mp;
    Node* tail;
    Node* head;
    int capacity;

    LRUCache(int capacity){
        this->capacity=capacity;
        tail=new Node(-1,-1);
        head=new Node(-1,-1);
        tail->prev=head;
        head->next=tail;
    }
    void deleteNode(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void InsertAfterHead(Node* node)
    {
        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node=mp[key];
        deleteNode(node);
        InsertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end())
       {
        Node* node=mp[key];
        node->val=value;

        deleteNode(node);
        InsertAfterHead(node);
       }
       else{
        if(mp.size()==capacity)
        {
            Node* del=tail->prev;
            mp.erase(del->key);
            deleteNode(del);
        }
        Node* node=new Node(key,value);
        InsertAfterHead(node);
        mp[key]=node;
       }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */