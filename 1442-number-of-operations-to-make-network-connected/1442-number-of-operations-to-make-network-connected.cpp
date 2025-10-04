class Disjoint
{
    vector<int> rank,size,parent;
    public:
    Disjoint(int n)
    {
        rank.resize(n,0);
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int find(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }

    void unionByRank(int a,int b)
    {
        int ult_a=find(a);
        int ult_b=find(b);

        if(ult_a==ult_b) return ;

        if(rank[ult_a]<rank[ult_b])
        {
            parent[ult_a]=ult_b;
        }
        else if(rank[ult_b]<rank[ult_a])
        {
            parent[ult_b]=ult_a;
        }
        else
        {
            parent[ult_b]=ult_a;
            rank[ult_a]++;
        }
    }

    void unionBySize(int a,int b)
    {
         int ult_a=find(a);
        int ult_b=find(b);

        if(ult_a==ult_b) return ;

        if(size[ult_a]<size[ult_b])
        {
            parent[ult_a]=ult_b;
            size[ult_b]+=size[ult_a];
        }
        else if(size[ult_b]<size[ult_a])
        {
            parent[ult_b]=ult_a;
            size[ult_a]+=size[ult_b];

        }
        else
        {
            parent[ult_b]=ult_a;
            size[ult_a]+=size[ult_b];
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
            
            ds.unionBySize(connections[i][0],connections[i][1]);
            
        }
        int components=0;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(ds.find(i));
        }
        components=st.size();
        return components-1;
    }
};