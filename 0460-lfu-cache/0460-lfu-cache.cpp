class LFUCache {
public:

    int cap;
    int minFreq;

    struct Node{
        int key,value,freq;
    };
    unordered_map<int,list<Node>> freqList;
    unordered_map<int,list<Node>::iterator>mp;


    LFUCache(int capacity) {
        cap=capacity;
        minFreq=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        auto it=mp[key];

        int k=it->key;
        int val=it->value;
        int freq=it->freq;

        freqList[freq].erase(it);

        if(freqList[freq].empty()){
             freqList.erase(freq);

             if(minFreq==freq) minFreq++;
}
    freqList[freq+1].push_back({k,val,freq+1});

    auto newIt=prev(freqList[freq+1].end());

    mp[key]=newIt;
    return val;

    }
    
    void put(int key, int value) {
        if(cap==0) return ;

        if(mp.find(key)!=mp.end()){
            mp[key]->value=value;
            get(key);
            return ;
        }

        if(mp.size()==cap){
            auto node=freqList[minFreq].front();
            mp.erase(node.key);

            freqList[minFreq].pop_front();

            if(freqList[minFreq].empty()){
                freqList.erase(minFreq);
            }
        }
            freqList[1].push_back({key,value,1});
            auto it=prev(freqList[1].end());

            mp[key]=it;
            minFreq=1;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */