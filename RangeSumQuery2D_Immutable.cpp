// Prefix Sum

class NumMatrix {
private:
    vector<vector<int>> preSum;  // preSum records the sum of the [0, 0, i-1, j-1] submatrix
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();  // the number of rows
        int n = matrix[0].size();  // the number of columns
        
        // construct Prefix Sum matrix
        preSum.resize(m+1, vector<int>(n+1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i-1][j-1] - preSum[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] + preSum[row1][col1] - preSum[row1][col2+1] - preSum[row2+1][col1];
    }
};
