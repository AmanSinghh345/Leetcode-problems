class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> umap;
        int ans = 0;
        int n = answers.size();

     
        for(int i = 0; i < n; i++) {
            umap[answers[i]]++;
        }

        
        for(auto it = umap.begin(); it != umap.end(); it++) {
            
            if(it->first == 0) {
                ans += it->second;
            }
            
            else if(it->second > it->first + 1) {
                int pairs = it->second / (it->first + 1);
                int lefts = it->second % (it->first + 1);


                if(lefts > 0) pairs++;
                ans += (it->first + 1) * pairs;
            } else {
                
                ans += (it->first + 1);
            }
        }

        return ans;
    }
};
