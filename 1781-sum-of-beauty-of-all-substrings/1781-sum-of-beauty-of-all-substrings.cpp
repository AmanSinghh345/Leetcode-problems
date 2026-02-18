class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
           
            for(int j=i;j<n;j++)
            {
                 int maxFreq=0;
            int minFreq=INT_MAX;
                freq[s[j]-'a']++;
                for(int k=0;k<26;k++)
                {
                    if(freq[k]>0)
                    {
                        maxFreq=max(maxFreq,freq[k]);
                        minFreq=min(minFreq,freq[k]);
                    }

                }
                ans+=(maxFreq-minFreq);
            }
        }
        return ans;
    }
};