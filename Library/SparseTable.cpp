// ---------------------------------- Sparse Table -----------------------------------------

class SparseTable {
private:
    using T = long long; // Integer Type
    const T and_identity = ~0LL;
    const T or_identity = 0;
    const T min_identity = std::numeric_limits<T>::max();
    const T max_identity = std::numeric_limits<T>::min();
    const T gcd_identity = 0;
    const T lcm_identity = 1;
    
    std::vector<std::vector<T>> dp;
    int k = 0, n;
    
    T identity_element = min_identity;
    T sparse_operation(T a, T b) { 
        return std::min(a, b);
    }

public:
    SparseTable(std::vector<T> &v) {
        n = v.size();
        k = std::__lg(n);
        dp.resize(k + 1, std::vector<T>(n));
        std::ranges::copy(v, dp[0].begin());
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                auto a = dp[i - 1][j];
                auto b = dp[i - 1][j + (1 << (i - 1))];
                dp[i][j] = sparse_operation(a, b);
            }
        }
    }

    T query(int l, int r) {
        assert(l <= r && r < n);
        T ans = identity_element;
        for (int i = k; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                auto a = ans;
                auto b = dp[i][l];
                ans = sparse_operation(a, b);
                l += 1 << i;
            }
        }
        return ans;
    }

    T query_fast(int l, int r) {  // only use if operation is idempotent!
        assert(l <= r && r < n);
        int i = std::__lg(r - l + 1);
        auto a = dp[i][l];
        auto b = dp[i][r - (1 << i) + 1];
        return sparse_operation(a, b);
    }
};

// ------------------------------------------------------------------------------------------