class Solution {
public:
    bool find(vector<int>& ranks, int cars, long long mini) {
        long long completed = 0;
        for (int rank : ranks) {
            long long x = mini / rank;
            long long y = (long long)sqrt(x);  
            completed += y;
        }
        return completed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());
        long long l = 1, h = 1LL * 1e14; 
      
        while (l < h) {
            long long mid = l + (h - l) / 2; 
            if (find(ranks, cars, mid))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
