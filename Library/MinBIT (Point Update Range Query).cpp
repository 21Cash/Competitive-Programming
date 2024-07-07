/* Point Update and Range Query Min BIT */
struct MinBIT {
    vector<long long> bit;
    long long n;
    const long long INF = (long long)1e9;

    MinBIT(long long n) {
        this->n = n;
        bit.assign(n, INF);
    }

    MinBIT(vector<long long> a) : MinBIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    long long get_min(long long r) {
        long long ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(long long idx, long long val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};