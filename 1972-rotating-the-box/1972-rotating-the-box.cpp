class Solution {
public:
    void gravity(vector<vector<char>>& ans,int cnt,int x,int y){
        while(cnt>0){
            ans[x][y]='#';
            x--,cnt--;
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        
        vector<vector<char>> ans(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++){
            int cnt=0; //cnt # value
            for(int j=0;j<n;j++){
                if(box[i][j]=='#') 
                cnt++;
                else if(box[i][j]=='*'){
                    ans[j][m-i-1]='*';
                    gravity(ans,cnt,j-1,m-i-1);
                    cnt=0;
                }
               
            }
             if(cnt>0)
                  gravity(ans,cnt,n-1,m-i-1);
        }
        return ans;
    }
};