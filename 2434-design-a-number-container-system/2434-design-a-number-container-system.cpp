class NumberContainers {
public:
     unordered_map<int,int> umap;
     unordered_map<int,set<int>> umap2;
    NumberContainers() {
       
    }
    
    void change(int index, int number) {
        if(umap.find(index)!=umap.end()){
            umap2[umap[index]].erase(index);
            if(umap2[umap[index]].empty()){
                umap2.erase(umap[index]);
            }
        }

        umap[index]=number;
        umap2[number].insert(index);
    }
    
    int find(int number) {
        if(umap2.find(number)!=umap2.end() && !umap2.empty())
            return *umap2[number].begin();
        return -1;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */