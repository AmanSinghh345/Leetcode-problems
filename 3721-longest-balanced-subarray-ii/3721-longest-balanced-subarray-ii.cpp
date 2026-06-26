class Solution {
public:
    class SegmentTree{
        public: 
        int n;
        vector<int> mn,mx,lazy;
        SegmentTree(int n){
            this->n=n;
            mn.assign(4*(n+1),0);
            mx.assign(4*(n+1),0);
            lazy.assign(4*(n+1),0);
        }
        void apply(int node,int val){
            mn[node]+=val;
            mx[node]+=val;
            lazy[node]+=val;
        }
        void pushdown(int node){
            if(lazy[node]!=0){
                apply(2*node,lazy[node]);
                apply(2*node+1,lazy[node]);
                lazy[node]=0;
            }
        }
        void pushup(int node){
            mn[node]=min(mn[2*node],mn[2*node+1]);
            mx[node]=max(mx[2*node],mx[2*node+1]);
        }
        void update(int node,int start,int end,int l,int r,int val){
            if(r<start || end<l ) return ;

            if(l<=start && end<=r) {
                apply(node,val);
                return ;
            }

            pushdown(node);

     int mid = start + (end - start) / 2;

            update(2*node,start,mid,l,r,val);
            update(2*node+1,mid+1,end,l,r,val);
            pushup(node);
        }
        int query(int node,int start,int end,int target){
            if(start==end) return start;

            pushdown(node);
            int mid=(start+end)/2;
            if(mn[2*node]<=target && target<=mx[2*node]){
                return query(2*node,start,mid,target);
            }
            return query(2*node+1,mid+1,end,target);
        }
    };
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        SegmentTree seg(n);
        unordered_map<int,int> umap;
        int now=0;
        int maxLen=0;
        for(int i=1;i<=n;i++){
            int x=nums[i-1];
            int det=(x&1)? 1 : -1 ;
            if(umap.count(x)){
                int p=umap[x];
                seg.update(1,0,n,p,n,-det);
                now-=det;
            }

            seg.update(1,0,n,i,n,det);
            now+=det;

            umap[x]=i;
            int pos=seg.query(1,0,n,now);
            maxLen=max(maxLen,i-pos);
        }
        return maxLen;
    }
};