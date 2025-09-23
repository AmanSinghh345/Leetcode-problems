class Solution {
public:
    string numbertobinary(int num)
    {
        string res="";
        while(num!=0)
        {
            int rem=num%2;
            char ch=rem+'0';
            res=ch+res;
            num/=2;
        }
        return res;
    }
    string binarytogrey(string binary)
    {
        string res="";
        res+=binary[0];
        for(int i=1;i<binary.size();i++)
        {
            int lastbit=binary[i-1]-'0';
            int currbit=binary[i]-'0';
            int val=lastbit^currbit;
            char ch=val+'0';
            res+=ch;
        }
        return res;
    }
    int binarytonumber(string binary)
    {
            int n=binary.size();
            reverse(binary.begin(),binary.end());
            int res=0;
            for(int i=0;i<n;i++)
            {
                if(binary[i]=='1')
                res+=(1<<i);
            }
            return res;
    }
    vector<int> grayCode(int n) {
        int lastEle=1<<(n);
        lastEle--;
        vector<int> ans;
        for(int num=0;num<=lastEle;num++)
        {
            string binary=numbertobinary(num);
            string grey=binarytogrey(binary);
            int val=binarytonumber(grey);
            ans.push_back(val);
        }
        return ans;
    }
};