class DisjointSet{
    public : 
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }

    void unionBySize(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return;
        if(size[pa]<size[pb]){
            size[pb]+=size[pa];
            parent[pa]=pb;
        }
        else{
            size[pa]+=size[pb];
            parent[pb]=pa;
    }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0,maxCol=0;
        for(auto & stone : stones){
            maxRow=max(maxRow,stone[0]);
            maxCol=max(maxCol,stone[1]);
        }

        int totalNodes=maxRow+maxCol+2;

        DisjointSet ds(totalNodes);

        unordered_set<int> usedNodes;

        for(auto& stone : stones){
            int row=stone[0];
            int col=stone[1]+maxRow+1;

            ds.unionBySize(row,col);
            usedNodes.insert(row);
            usedNodes.insert(col);
        }

        int components=0;
        for(int x:usedNodes){
            if(ds.find(x)==x) components++;
        }
        return stones.size()-components;
    }
};