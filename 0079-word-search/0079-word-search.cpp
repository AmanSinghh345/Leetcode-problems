class Solution {
public:
    bool find(int i,int j,int next,vector<vector<char>>& board,string& word){

        //base case
        if(next==word.size()) return true;

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(word[next]!=board[i][j]) return false;

        char temp=board[i][j];
        board[i][j]='#';

        bool found=find(i-1,j,next+1,board,word)||
                    find(i,j+1,next+1,board,word)||
                    find(i+1,j,next+1,board,word)||
                    find(i,j-1,next+1,board,word);

        
        board[i][j]=temp;
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(find(i,j,0,board,word)) return true;
            }
        }
        return false;
    }
};