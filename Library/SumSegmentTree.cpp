class SegmentTree {
private:
    int n;
    std::vector<long long> t;

    void build(const std::vector<long long>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    long long sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, std::min(r, tm))
               + sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

public:
    SegmentTree() {
        n = 0;
    }

    void init(const std::vector<long long>& a) {
        n = a.size();
        t.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    long long query_sum(int l, int r) {
        return sum(1, 0, n - 1, l, r);
    }
    
    void set_val(int index, long long new_val) {
        update(1, 0, n - 1, index, new_val);
    }
};