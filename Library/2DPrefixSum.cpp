/* ------------------ 2D Prefix Sum ---------------------------- */

const int MXROWS = 501;
const int MXCOLS = 501; 

ll sumMat[MXROWS][MXCOLS];

class Prefix2D {
private:
    ll R, C;
    ll getSum(ll r, ll c) {
        if(r < 0 || r >= R || c < 0 || c >= C) return 0LL;
        return sumMat[r][c]; 
    }
public:
    Prefix2D() { }
    Prefix2D(vector<vector<ll>>& grid) {
        memset(sumMat, 0, sizeof(sumMat));
        R = grid.size(), C = grid[0].size();
        
        for(ll r = 0; r < R; r++) {
            ll rowSum = 0;
            for(ll c = 0;c < C; c++) {
                rowSum += grid[r][c];
                sumMat[r][c] = rowSum + (r - 1 >= 0 ? sumMat[r - 1][c] : 0); 
            }
        }
    }
    
    void init(vector<vector<ll>> &grid) {
        memset(sumMat, 0, sizeof(sumMat));
        R = grid.size(), C = grid[0].size();
        
        for(ll r = 0; r < R; r++) {
            ll rowSum = 0;
            for(ll c = 0;c < C; c++) {
                rowSum += grid[r][c];
                sumMat[r][c] = rowSum + (r - 1 >= 0 ? sumMat[r - 1][c] : 0); 
            }
        }
    }
    
    ll query_sum(ll topRow, ll topCol, ll bottomRow, ll bottomCol) {
        ll total = getSum(bottomRow, bottomCol);

        ll topBox = getSum(topRow - 1, bottomCol);
        ll sideBox = getSum(bottomRow, topCol - 1);

        ll toAdd = getSum(topRow - 1, topCol - 1);

        ll res = total - topBox - sideBox + toAdd;
        return res;
    }
};

/* ------------------ 2D Prefix Sum ---------------------------- */