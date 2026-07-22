class Solution {
    class SegmentTree{
        public:
        vector<int> a;
        int n;
        vector<int> tree;
        SegmentTree(vector<int>& a){
            this->a=a;
            n=a.size();
            tree.assign(4*max(1,n),0);
            if(n>0)
            build(0,0,n-1);
        }
        void build(int index,int start,int end){
            if(start==end){
                tree[index]=a[start];
                return;
            }
            int mid=start+(end-start)/2;
            int leftChild=2*index+1;
            int rightChild=2*index+2;
           build(leftChild,start,mid);
           build(rightChild,mid+1,end);
           tree[index]=max(tree[leftChild],tree[rightChild]);
        }
        int query(int index,int start,int end,int l,int r){
            if(l<=start && end<=r) return tree[index];
            if(end<l or r<start) return 0;
             int mid=start+(end-start)/2;
            int leftChild=2*index+1;
            int rightChild=2*index+2;
            int a=query(leftChild,start,mid,l,r);
            int b=query(rightChild,mid+1,end,l,r);
            return max(a,b);
        }
        int query(int l,int r){
            if(n==0 or l>r) return 0; 
            return query(0,0,n-1,l,r);
        }
    };
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int one=0;
        for(char c:s){
            if(c=='1') one++;
        }
        vector<int> blockLeft,blockRight,blockLength;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                int left=i;
                while(i+1<n && s[i+1]=='0') i++;
                int right=i;
                blockLeft.push_back(left);
                blockRight.push_back(right);
                blockLength.push_back(right-left+1);
            }
        }
        vector<int> pairSum;
        for(int i=0;i+1<blockLength.size();i++){
            int val=blockLength[i]+blockLength[i+1];
            pairSum.push_back(val);
        }

        SegmentTree seg(pairSum);
        vector<int> ans;
        for(auto & it:queries){
            int l=it[0];
            int r=it[1];

            int firstBlock=lower_bound(blockRight.begin(),blockRight.end(),l)-blockRight.begin();

            int lastBlock=upper_bound(blockLeft.begin(),blockLeft.end(),r)-blockLeft.begin()-1;

            //no zero block
            if(firstBlock>=blockLength.size()|| lastBlock<0 || firstBlock>lastBlock){
                ans.push_back(one);
                continue;
            }
            //only one zero block
            if(firstBlock==lastBlock){
                ans.push_back(one);
                continue;
            }

            int len1=min(blockRight[firstBlock],r)-max(blockLeft[firstBlock],l)+1;
            int len2=min(blockRight[lastBlock],r)-max(blockLeft[lastBlock],l)+1;

            int maxi=0;

            if(lastBlock==firstBlock+1) maxi=len1+len2;
            else {
                 int val1=len1+blockLength[firstBlock+1];
                 int val2=len2+blockLength[lastBlock-1];
                 int val3=seg.query(firstBlock+1,lastBlock-2);
                 maxi=max({val1,val2,val3});
            }
            ans.push_back(maxi+one);
        }
        return ans;
    }
};