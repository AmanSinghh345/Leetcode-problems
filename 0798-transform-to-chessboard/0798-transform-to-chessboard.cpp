class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();

        // Extract first row and first column
        vector<int> firstRow = board[0];
        vector<int> firstCol(n);
        for (int i = 0; i < n; i++) {
            firstCol[i] = board[i][0];
        }

        // Count ones in first row and first column
        int rowOnes = accumulate(firstRow.begin(), firstRow.end(), 0);
        int colOnes = accumulate(firstCol.begin(), firstCol.end(), 0);

        // Check if row and column ones are within valid limits
        if (rowOnes != n / 2 && rowOnes != (n + 1) / 2) return -1;
        if (colOnes != n / 2 && colOnes != (n + 1) / 2) return -1;

        // Count misplaced rows and columns
        int rowMisplace = 0, colMisplace = 0;
        for (int i = 0; i < n; i++) {
            if (board[i] != firstRow && board[i] != inverseRow(firstRow)) return -1;
            if (board[i][0] == (i % 2)) rowMisplace++;
        }

        for (int j = 0; j < n; j++) {
            vector<int> column(n);
            for (int i = 0; i < n; i++) {
                column[i] = board[i][j];
            }
            if (column != firstCol && column != inverseRow(firstCol)) return -1;
            if (board[0][j] == (j % 2)) colMisplace++;
        }

        // Adjust swaps based on even or odd size of board
        if (n % 2 == 0) {
            rowMisplace = min(rowMisplace, n - rowMisplace);
            colMisplace = min(colMisplace, n - colMisplace);
        } else {
            if (rowMisplace % 2 != 0) rowMisplace = n - rowMisplace;
            if (colMisplace % 2 != 0) colMisplace = n - colMisplace;
        }

        return (rowMisplace + colMisplace) / 2;
    }

    vector<int> inverseRow(vector<int> row) {
        for (int& num : row) num = 1 - num;
        return row;
    }
};
