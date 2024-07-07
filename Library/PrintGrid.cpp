void print_grid(vector<vector<int>> &grid) {
    int R = grid.size(), C = grid[0].size(); 
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            cout << grid[r][c] << " "; 
        }
        cout << "\n";
    }
}