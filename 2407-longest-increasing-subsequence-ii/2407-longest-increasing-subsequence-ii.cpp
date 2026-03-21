class SegTree{
    public:
    vector<int> tree;
    int n;
    SegTree(int a){
        n=a;
        tree.resize(4*n,0);
    }
    void point_update(int index,int start,int end,int pos,int value){
        if(start==end){
            tree[index]=max(tree[index],value);
            return ;
        }
        int mid=(start+end)/2;
        int leftChild=2*index;
        int rightChild=2*index+1;
        if(pos<=mid) point_update(leftChild,start,mid,pos,value);
        else point_update(rightChild,mid+1,end,pos,value);
        tree[index]=max(tree[leftChild],tree[rightChild]);
    }
    int query(int index,int start,int end,int l,int r){
        //No overlap
        if(r<start or end<l) return 0;
        //Complete overlap
        if(l<=start and end<=r) return tree[index];
        //partial overlap
        int mid=(start+end)/2;
        int leftChild=2*index;
        int rightChild=2*index+1;
        int a=query(leftChild,start,mid,l,r);
        int b=query(rightChild,mid+1,end,l,r);
        return max(a,b);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        SegTree seg(maxi);
        int ans=0;
        for(int x:nums){
            int l=max(0,x-k);
            int r=x-1;
            int curr=seg.query(1,0,maxi,l,r);
           
                 curr++;
            seg.point_update(1,0,maxi,x,curr);
        
            ans=max(ans,curr);
            
        }  
        return ans;
    }
};