class Solution {
public:

    vector<int> SPF(int N) {

        

        vector<int> spf(N);

        for (int i = 0; i < N; i++) {
            spf[i] = i;
        }

        for (long long i = 2; i * i < N; i++) {

            if (spf[i] == i) {

                for (long long j = i * i; j < N; j += i) {

                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }

    vector<int> getFactors(int n, vector<int>& spf) {

        vector<int> factors;

        while (n != 1) {

            int p = spf[n];

            factors.push_back(p);

            while (n % p == 0) {
                n /= p;
            }
        }

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return 0;
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> spf = SPF(mx+1);

        unordered_map<int, vector<int>> umap;

    
        for (int i = 0; i < n; i++) {

            vector<int> factors = getFactors(nums[i], spf);

            for (auto f : factors) {
                umap[f].push_back(i);
            }
        }

        vector<int> dist(n, INT_MAX);

        queue<int> q;

        q.push(0);

        dist[0] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            int d = dist[node];

            
            if (node - 1 >= 0 && dist[node - 1] > d + 1) {

                dist[node - 1] = d + 1;

                q.push(node - 1);
            }

            
            if (node + 1 < n && dist[node + 1] > d + 1) {

                dist[node + 1] = d + 1;

                q.push(node + 1);
            }

        
            if (spf[nums[node]] == nums[node]) {

                int prime = nums[node];

                for (auto nxt : umap[prime]) {

                    if (dist[nxt] > d + 1) {

                        dist[nxt] = d + 1;

                        q.push(nxt);
                    }
                }

                
                umap[prime].clear();
            }
        }

        return dist[n - 1];
    }
};