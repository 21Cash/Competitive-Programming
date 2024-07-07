// Rotates the given Grid 'K' Times
vector<vector<ll>> rotate_grid(vector<vector<ll>> &grid, int K, bool clockwise) {
    int rows = grid.size();
    int cols = grid[0].size();

    K %= 4;
    if (!clockwise) {
        K = (4 - K) % 4; 
    }

    for (int i = 0; i < K; ++i) {
        vector<vector<ll>> newGrid(cols, vector<ll>(rows));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                newGrid[c][rows - 1 - r] = grid[r][c];
            }
        }
        grid = newGrid;
        swap(rows, cols);
    }

    return grid;
}