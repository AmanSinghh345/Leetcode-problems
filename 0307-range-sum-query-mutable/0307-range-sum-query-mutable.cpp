class NumArray {
public:
    vector<int> arr;
    int n;
    void build(int node,int start,int end,vector<int>& nums){
        if(start==end){
            arr[node]=nums[start];
            return;
        }
        int mid=(start+end)/2;
        int leftChild=2*node;
        int rightChild=2*node+1;
        build(leftChild,start,mid,nums);
        build(rightChild,mid+1,end,nums);
        arr[node]=arr[leftChild]+arr[rightChild];
    }
    int range(int node,int start,int end,int l,int r)
    {
        if(r<start or end<l) return 0;
        else if(l<=start and end<=r) return arr[node];
        //partial
        int mid=(start+end)/2;
        int leftChild=2*node;
        int rightChild=2*node+1;
        int a=range(leftChild,start,mid,l,r);
        int b=range(rightChild,mid+1,end,l,r);
        return a+b;
    }
    void pointUpdate(int node,int start,int end,int index,int val)
    {
        if(start==end)
        {
            arr[node]=val;
            
            return;
        }
        int mid=(start+end)/2;
        int leftChild=2*node;
        int rightChild=2*node+1;
        if(index<=mid)
        {
            pointUpdate(leftChild,start,mid,index,val);
        }
        else pointUpdate(rightChild,mid+1,end,index,val);
        arr[node]=arr[leftChild]+arr[rightChild];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr.resize(4*n);
        build(1,0,n-1,nums);
    }
    
    void update(int index, int val) {
        pointUpdate(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
       return range(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */