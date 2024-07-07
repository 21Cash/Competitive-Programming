void floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
    int m = image.size(), n = image[0].size();
    int initialColor = image[sr][sc];
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second; q.pop();
        image[curRow][curCol] = color;
        for(int i = 0; i < 4; i++) {
            int tRow = curRow + delRow[i];
            int tCol = curCol + delCol[i];
            if(tRow >= 0 && tRow < m && tCol >= 0 && tCol < n && image[tRow][tCol] == initialColor 
                && image[tRow][tCol] != color) {
                q.push(make_pair(tRow, tCol));
            }
        }
    }
}