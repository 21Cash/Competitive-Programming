// ------------------------- AND Sparse Table --------------------------------

class SparseTable {
private:
    std::vector<std::vector<ll>> table;
    std::vector<ll> log;

    void build(const std::vector<ll>& arr) {
        ll n = arr.size();
        ll max_log = std::log2(n) + 1;

        log.resize(n + 1);
        log[1] = 0;
        for (ll i = 2; i <= n; ++i) {
            log[i] = log[i / 2] + 1;
        }

        table.resize(n, std::vector<ll>(max_log));
        for (ll i = 0; i < n; ++i) {
            table[i][0] = arr[i];
        }

        for (ll j = 1; (1 << j) <= n; ++j) {
            for (ll i = 0; (i + (1 << j) - 1) < n; ++i) {
                table[i][j] = table[i][j - 1] & table[i + (1 << (j - 1))][j - 1];
            }
        }
    }

public:
    SparseTable(const std::vector<ll>& arr) {
        build(arr);
    }

    ll query(ll l, ll r) {
        ll j = log[r - l + 1];
        return table[l][j] & table[r - (1 << j) + 1][j];
    }
};

// -------------------------------------------------------------------------------