namespace binary_search_operations {

    // Get First Element in range [L, R] 
    ll get_first_val(vector<ll> &A, ll L, ll R) {
        auto it = lower_bound(A.begin(), A.end(), L);
        if (it != A.end() && *it <= R) {
            return *it;
        }
        return -1;
    }
            
    // Get Last Element in range [L, R] 
    ll get_last_val(vector<ll> &A, ll L, ll R) {
        auto it = upper_bound(A.begin(), A.end(), R);
        if (it != A.begin()) {
            --it;
            if (*it >= L) {
                return *it;
            }
        }
        return -1;
    }
    
    template<typename T, typename U>
    T first_true(T lo, T hi, U f) {
        ++hi;
        while (lo < hi) {
            T mid = lo + (hi - lo) / 2;
            f(mid) ? hi = mid : lo = mid + 1;
        }
        return lo;
    }

    template<typename T, typename U>
    T last_true(T lo, T hi, U f) {
        --lo;
        while (lo < hi) {
            T mid = lo + (hi - lo + 1) / 2;
            f(mid) ? lo = mid : hi = mid - 1;
        }
        return lo;
    }
}

using namespace binary_search_operations;