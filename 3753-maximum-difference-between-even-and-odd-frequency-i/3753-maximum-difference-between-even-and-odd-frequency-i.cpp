class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> umap;
        int n=s.size();
        for(int i=0;i<n;i++) {
            umap[s[i]]++;
        }
        int maxodd=INT_MIN,maxeven=INT_MIN,minodd=INT_MAX,mineven=INT_MAX;
        for(auto it=umap.begin();it!=umap.end();it++){
               if(it->second%2==0){
                   maxeven=max(maxeven,it->second);
                   mineven=min(mineven,it->second);
               } 
             else{
                 maxodd=max(maxodd,it->second);
                 minodd=min(minodd,it->second);
             }
        } 
        int diff1=maxodd-mineven;
       
        return diff1;
    }
};