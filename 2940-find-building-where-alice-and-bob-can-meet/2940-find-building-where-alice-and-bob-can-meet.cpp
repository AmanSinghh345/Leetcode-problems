class SegTree{
    public:
    vector<int> tree;
    int val;
    vector<int> arr;
    SegTree(vector<int> a){
        arr=a;
        int n=arr.size();
        tree.resize(4*n);
        build(0,0,n-1);
    }
    void build(int index,int start,int end){
        if(start==end){
            tree[index]=arr[start];
            return;
        }
        int mid=(start+end)/2;
        int leftChild=2*index+1;
        int rightChild=2*index+2;
        build(leftChild,start,mid);
        build(rightChild,mid+1,end);
        tree[index]=max(tree[leftChild],tree[rightChild]);
    }
    int query(int index,int start,int end,int r,int th){
        if(end<r or tree[index]<=th) return -1;
        if(start==end) return start;
        int mid=(start+end)/2;
        int leftChild=2*index+1;
        int rightChild=2*index+2;
        int left=query(leftChild,start,mid,r,th);
        if(left!=-1) return left;
        int right=query(rightChild,mid+1,end,r,th);
        return right;
    }
};
class Solution {
public:
    
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        SegTree seg(heights);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
             if(l>r) swap(l,r);
            if(l==r) ans.push_back(l);
            else if(heights[l]<heights[r]) ans.push_back(r);
            else {
               
                int th=max(heights[l],heights[r]);
               int v= seg.query(0,0,heights.size()-1,r+1,th);
               ans.push_back(v);
            }
        }
        return ans;
    }
};