// ------------------------- Min Segment Treee (Range Query & Point Update) ----------------------------
class MinSegmentTree {
private:
    int n;
    std::vector<ll> t;

    void build(const std::vector<ll>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = std::min(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll min_query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return LLONG_MAX;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return std::min(min_query(v * 2, tl, tm, l, std::min(r, tm)),
                        min_query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = std::min(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    MinSegmentTree() {
        n = 0;
    }

    void init(const std::vector<ll>& a) {
        n = a.size();
        t.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    ll query_min(int l, int r) {
        return min_query(1, 0, n - 1, l, r);
    }
    
    void set_val(int index, ll new_val) {
        update(1, 0, n - 1, index, new_val);
    }
};
// -------------------------------------------------------------------------------------------------