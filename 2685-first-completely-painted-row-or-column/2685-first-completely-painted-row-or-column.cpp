class Solution {
public:
  

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int M = mat.size(); 
        int N = mat[0].size();  


        unordered_map<int, pair<int, int>> valueToPosition;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                valueToPosition[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCnt(M, 0);
        vector<int> columnCnt(N, 0);

        for (int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            auto position = valueToPosition[value]; 
            int row = position.first;
            int col = position.second;

            
            rowCnt[row]++;
            columnCnt[col]++;

        
            if (rowCnt[row] == N || columnCnt[col] == M) {
                return i;  
            }
        }

        return -1;
    }
};
