ll prefix[205][205];

class MatrixSum {
private:
    int R, C;
    ll getSum(int r, int c) {
        if(r < 0 || r >= R || c < 0 || c >= C) return 0LL;
        return prefix[r][c]; 
    }
public:
    MatrixSum(vector<vector<int>>& grid) {
        memset(prefix, 0, sizeof(prefix));
        R = grid.size(), C = grid[0].size();
        
        for(int r = 0; r < R; r++) {
            ll rowSum = 0;
            for(int c = 0;c < C; c++) {
                rowSum += grid[r][c];
                prefix[r][c] = rowSum + (r - 1 >= 0 ? prefix[r - 1][c] : 0); 
            }
        }

    }
    
    // Returns Sum of the Sub matrix [topRow, toCol] & [bottomRow, bottomCol]
    ll querySum(int topRow, int topCol, int bottomRow, int bottomCol) {
        ll total = getSum(bottomRow, bottomCol);

        ll topBox = getSum(topRow - 1, bottomCol);
        ll sideBox = getSum(bottomRow, topCol - 1);

        ll toAdd = getSum(topRow - 1, topCol - 1);

        ll res = total - topBox - sideBox + toAdd;
        return res;
    }
};