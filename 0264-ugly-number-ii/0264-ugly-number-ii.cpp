class Solution {
public:
  typedef long long ll;
    int nthUglyNumber(int n) {
       priority_queue<ll,vector<ll>,greater<ll>>  p;
       unordered_set<ll> unique;
       p.push(1);
       unique.insert(1);
       ll val=1;
       while(n>0){
        val=p.top();
        p.pop();
        n--;
        if(unique.find(val*2)==unique.end()){
           p.push(val*2);
            unique.insert(val*2);
        }
        if(unique.find(val*3)==unique.end()){
            p.push(val*3);
            unique.insert(val*3);
        }
        if(unique.find(val*5)==unique.end()){
            p.push(val*5);
            unique.insert(val*5);
        }
       }
       return val;

    
    }
};