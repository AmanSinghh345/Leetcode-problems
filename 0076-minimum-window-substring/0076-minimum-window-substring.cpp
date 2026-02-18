class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> umap;
        for(int i=0;i<m;i++)
        {
            umap[t[i]]++;
        }

        int cnt=umap.size();
        int have=0;

        unordered_map<char,int> temp;
        int l=0;
        int r;
        int minLen=INT_MAX;
        int start=0;

        for(r=0;r<n;r++)
        {
            temp[s[r]]++;

            if(umap.count(s[r]) and umap[s[r]]==temp[s[r]]) have++;

            while(have==cnt)
            {
                if((r-l+1)<minLen)
                {
                    minLen=r-l+1;
                    start=l;
                }
                temp[s[l]]--;
                if(umap.count(s[l]) and temp[s[l]]<umap[s[l]]) have--;
                l++;
            }
           
        }
       if(minLen==INT_MAX) return "";
       return s.substr(start,minLen);
    }
};