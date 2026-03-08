class Disjoint{
    vector<int> parent,rank;
    public:
    Disjoint(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int find(int node)
    {
        if(node==parent[node]) return node;
        else return parent[node]=find(parent[node]);
    }
    void unionbyrank(int a,int b)
    {
        int ult_a=find(a);
        int ult_b=find(b);
        if(ult_a==ult_b) return ;
        if(rank[ult_a]<rank[ult_b]){
            parent[ult_a]=ult_b;
        }
        else if(rank[ult_b]<rank[ult_a])
        {
            parent[ult_b]=ult_a;
        }
        else {
            parent[ult_b]=ult_a;
            rank[ult_a]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        Disjoint ds(n);

        for(int i=0;i<connections.size();i++)
        {
            ds.unionbyrank(connections[i][0],connections[i][1]);
        }
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(ds.find(i));
        }
        int components=st.size();
        int ops=components-1;
        return ops;
    }
};