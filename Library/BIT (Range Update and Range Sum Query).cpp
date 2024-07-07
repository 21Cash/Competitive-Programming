// BIT (Range Update and Range Sum Query)
class BIT {
private:
    vector<ll> B1, B2;
    int N;

    void add(vector<ll>& b, int idx, ll x) {
        while (idx < N) {
            b[idx] += x;
            idx |= idx + 1;
        }
    }

    ll sum(const vector<ll>& b, int idx) {
        ll total = 0;
        while (idx >= 0) {
            total += b[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return total;
    }

public:
    void init(int size) {
        N = size;
        B1.assign(N, 0);
        B2.assign(N, 0);
    }
    
    void init(const vector<ll>& arr) {
        N = arr.size();
        B1.assign(N, 0);
        B2.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            range_add(i, i, arr[i]);
        }
    }
    
    BIT() { }
    
    BIT(int size) {
        init(size);
    }
    
    BIT(vector<ll>& arr) {
        init(arr);
    }

    void range_add(int l, int r, ll x) {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * l);
        add(B2, r + 1, -x * (r + 1));
    }

    ll prefix_sum(int idx) {
        return sum(B1, idx) * (idx + 1) - sum(B2, idx);
    }
    
    ll range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
    
    ll get(int idx) {
        return range_sum(idx, idx);
    }
};