/* 2D BIT */

struct BIT2D {
    vector<vector<long long>> bit;
    int n, m;
    
    BIT2D() { }
    
    void init(int _n, int _m) {
        n = _n;
        m = _m;
        bit.assign(n, vector<long long>(m, 0));
    }
    
    void init(const vector<vector<long long>>& arr) {
        n = arr.size();
        m = arr[0].size();
        bit.assign(n, vector<long long>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                add(i, j, arr[i][j]);
    }

    void add(int x, int y, long long delta) {
        for (int i = x; i < n; i |= i + 1)
            for (int j = y; j < m; j |= j + 1)
                bit[i][j] += delta;
    }
    
    // Returns Sum formed by rectangle [0, 0] (Top Left Coord), [x, y] (Bottom right Coord)
    long long sum(int x, int y) {
        long long ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }
    
    // Returns the sum of the rect
    long long rect_sum(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
        if (topLeftX > bottomRightX || topLeftY > bottomRightY || topLeftX < 0 || topLeftY < 0 || bottomRightX >= n || bottomRightY >= m)
            return 0;

        long long total = sum(bottomRightX, bottomRightY);
        if (topLeftX > 0) total -= sum(topLeftX - 1, bottomRightY);
        if (topLeftY > 0) total -= sum(bottomRightX, topLeftY - 1);
        if (topLeftX > 0 && topLeftY > 0) total += sum(topLeftX - 1, topLeftY - 1);
        return total;
    }
    
    // Adds Delta to the rect
    void range_add(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY, long long delta) {
        if (topLeftX > bottomRightX || topLeftY > bottomRightY || topLeftX < 0 || topLeftY < 0 || bottomRightX >= n || bottomRightY >= m)
            return;

        add(topLeftX, topLeftY, delta);
        if (bottomRightX + 1 < n)
            add(bottomRightX + 1, topLeftY, -delta);
        if (bottomRightY + 1 < m)
            add(topLeftX, bottomRightY + 1, -delta);
        if (bottomRightX + 1 < n && bottomRightY + 1 < m)
            add(bottomRightX + 1, bottomRightY + 1, delta);
    }
};