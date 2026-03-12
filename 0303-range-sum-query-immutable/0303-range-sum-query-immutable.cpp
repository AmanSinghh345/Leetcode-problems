int MAXN=100005;

 int segTree[100005];
void build(int node,int start,int end,vector<int> &nums)
{
    if(start==end)
    {
        segTree[node]=nums[start];
        return ;
    }
    int mid=(start+end)/2;
    int leftChild=2*node;
    int rightChild=2*node+1;
    build(leftChild,start,mid,nums);
    build(rightChild,mid+1,end,nums);
    segTree[node]=segTree[leftChild]+segTree[rightChild];
}
int range(int node,int start,int end,int l,int r)
{   
    //NO overlap
    if(r<start or end<l) return 0;
    // complete overlap
    if(l<=start and end<=r) return segTree[node];
    int mid=(start+end)/2;
    int leftChild=2*node;
    int rightChild=2*node+1;
    int a=range(leftChild,start,mid,l,r);
    int b=range(rightChild,mid+1,end,l,r);
    return a+b;
}
class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr=nums;
        int start=0;
        int end=nums.size()-1;
        build(1,start,end,nums);
    }
    
    int sumRange(int left, int right) {
        int start=0;
        int end=arr.size()-1;
        return range(1,start,end,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */