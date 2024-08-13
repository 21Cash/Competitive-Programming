/* 2D BIT */

class BIT2D {
private:
    vector<vector<vector<ll>>> M, A;
    int R;
    int C;
public:
    // All set to by default
    BIT2D(int n, int m) { // Pass Number Of Rows, Cols
        this->R = n + 1;
        this->C = m + 1;
        M.assign(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2, 0)));
        A.assign(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2, 0)));
    }
 
private:
    void upd2(vector<vector<vector<ll>>>& t, int x, int y, long long mul,
              long long add) {
        for (int i = x; i < R; i += i & -i) {
            for (int j = y; j < C; j += j & -j) {
                t[i][j][0] += mul;
                t[i][j][1] += add;
            }
        }
    }
 
    void upd1(int x, int y1, int y2, long long mul, long long add) {
        upd2(M, x, y1, mul, -mul * (y1 - 1));
        upd2(M, x, y2, -mul, mul * y2);
        upd2(A, x, y1, add, -add * (y1 - 1));
        upd2(A, x, y2, -add, add * y2);
    }
 
    long long query2(vector<vector<vector<ll>>>& t, int x, int y) {
        long long mul = 0, add = 0;
        for (int i = y; i > 0; i -= i & -i) {
            mul += t[x][i][0];
            add += t[x][i][1];
        }
        return mul * y + add;
    }
 
    long long query1(int x, int y) {
        long long mul = 0, add = 0;
        for (int i = x; i > 0; i -= i & -i) {
            mul += query2(M, i, y);
            add += query2(A, i, y);
        }
        return mul * x + add;
    }
 
public:
    // NOTE : Arguments passed must be 0 - Based Indexed;
    // Adds Delta to the rect
    void range_add(int top_left_x, int top_left_y, int bottom_right_x, int bottom_right_y, long long val) {
        top_left_x++, top_left_y++, bottom_right_x++, bottom_right_y++;
        upd1(top_left_x, top_left_y, bottom_right_y, val, -val * (top_left_x - 1));
        upd1(bottom_right_x, top_left_y, bottom_right_y, -val, val * bottom_right_x);
    }
 
    // Returns the sum of the rect
    ll rect_sum(int top_left_x, int top_left_y, int bottom_right_x, int bottom_right_y) {
        top_left_x++, top_left_y++, bottom_right_x++, bottom_right_y++;
        return query1(bottom_right_x, bottom_right_y) - query1(top_left_x - 1, bottom_right_y) - query1(bottom_right_x, top_left_y - 1) + query1(top_left_x - 1, top_left_y - 1);
    }
};