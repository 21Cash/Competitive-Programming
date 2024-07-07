// Range Minimum Query
class RMQ {
private:
    vector<vector<ll>> table;
public:
    RMQ(const vector<ll>& arr) {
        ll n = arr.size();
        ll log2n = (log2(n)) + 1;

        table.assign(n, vector<ll>(log2n, 0));

        for (ll i = 0; i < n; ++i) {
            table[i][0] = arr[i];
        }

        for (ll j = 1; (1 << j) <= n; ++j) {
            for (ll i = 0; i + (1 << j) - 1 < n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    ll query_max(ll low, ll high) {
        ll k = (log2(high - low + 1));
        return min(table[low][k], table[high - (1 << k) + 1][k]);
    }
};