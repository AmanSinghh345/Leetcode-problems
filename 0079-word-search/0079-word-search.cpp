class Solution {
public:
    bool find(int i,int j,int  next,vector<vector<char>>& board, string& word){
        
        //base case
        if(next==word.size()){
            return true;
        }

        char temp=board[i][j];
        board[i][j]='#';

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && ni<(int)board.size() && nj>=0 && nj<(int)board[0].size() && board[ni][nj]==word[next]){
               
                if(find(ni,nj,next+1,board,word)) return true;
               
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        vector<pair<int,int>> pos;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]) pos.push_back({i,j});
            }
        }
        if(pos.size()==0) return false;
        

        for(int y=0;y<pos.size();y++){
            int i=pos[y].first;
            int j=pos[y].second;
    
            int next=1;
       if( find(i,j,next,board,word)) return true;

        }
        return false;
    }
};