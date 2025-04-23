class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> umap;
        while(n){
            int num=n;
            int sum=0;
            while(num>0){
            int ld=num%10;
            num/=10;
            sum+=ld;
            }
            umap[sum]++;
            n--;
        }
        int largest=INT_MIN;
        for(auto it=umap.begin();it!=umap.end();it++){
            if(it->second>largest) largest=it->second;
        }
        int cnt=0;
        for(auto it=umap.begin();it!=umap.end();it++){
            if(it->second==largest) cnt++;
        }
        return cnt;
    }
};