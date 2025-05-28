class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        //using two multiset to solve this question
        multiset<long long> lo,hi;

        //lamda function to balance the two multisets
        auto balance=[&](){
            //x x+1 -> x+1 x
            if(hi.size()>lo.size()){
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
            //x+2 x  -> x+1 x+1
            if(lo.size()>hi.size()+1){
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            }
          };

          vector<double> ans;

          for(int i=0;i<n;++i){
            //Insert and Balance
            if(lo.empty() or nums[i]<=*lo.rbegin()) lo.insert(nums[i]);
            else hi.insert(nums[i]);
            balance();

            //Remove and balance
           if(i>=k){
             long long out=nums[i-k];
            if(out<=*lo.rbegin()) lo.erase(lo.find(out));
            else hi.erase(hi.find(out));
            balance();
          }  

          //TO find
          if(i>=k-1){
            if(k%2==1) ans.push_back(*lo.rbegin());
            else ans.push_back(((double)*lo.rbegin()+(double)*hi.begin())/2.0);
          }
          }
          return ans;
    }
};