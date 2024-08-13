vector<vector<int>> transpose(const vector<vector<int>> &grid) {
    int rows = grid.size();
    if (rows == 0) return {};
    int cols = grid[0].size();
    
    vector<vector<int>> transposed(cols, vector<int>(rows));
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = grid[i][j];
        }
    }
    
    return transposed;
}