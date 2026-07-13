class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s="123456789";
        string a=to_string(low);
        string b=to_string(high);
        int len1=a.size();
        int len2=b.size();
        cout<<"len 1 : "<<len1<<endl;
        cout<<"len 2 : "<<len2 <<endl;
        for(int w=len1;w<=len2;w++){
            int l=0;
            while(l+w<10){
                cout<<l<<endl;
                string get=s.substr(l,w);
                cout<<get<<endl;
                int num=stoi(get);
                if(num>=low && num<=high) ans.push_back(num);
                l++;
            }
        }
        return ans;
    }
};