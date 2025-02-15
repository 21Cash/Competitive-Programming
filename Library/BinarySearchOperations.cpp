namespace binary_search_operations {

    // Get Index Of First Element in range [L, R], -1 if not found 
    ll get_first_index(vector<ll> &A, ll L, ll R) {
    auto it = lower_bound(A.begin(), A.end(), L);
        if (it != A.end() && *it <= R) {
            return it - A.begin();
        }
        return -1;
    }
            
    // Get Index of Last Element in range [L, R], -1 if not found
    ll get_last_index(vector<ll> &A, ll L, ll R) {
        auto it = upper_bound(A.begin(), A.end(), R);
        if (it != A.begin()) {
            --it;
            if (*it >= L) {
                return it - A.begin();
            }
        }
        return -1;
    }
    
    template<typename T, typename U>
    T first_true(T lo, T hi, U f) { // if f(X) not satisfied in range [lo, hi], returns (hi + 1);
        ++hi;
        while (lo < hi) {
            T mid = lo + (hi - lo) / 2;
            f(mid) ? hi = mid : lo = mid + 1;
        }
        return lo;
    }

    template<typename T, typename U>
    T last_true(T lo, T hi, U f) { // if f(X) not satisfied in range [lo, hi], returns (lo - 1);
        --lo;
        while (lo < hi) {
            T mid = lo + (hi - lo + 1) / 2;
            f(mid) ? lo = mid : hi = mid - 1;
        }
        return lo;
    }
    
    const double eps = 1e-9;
    
    template<typename T, typename U> 
    T first_double_true(T lo, T hi, U f) {  // If f(X) is not satisfied in range [lo, hi], returns (hi + eps);
        hi += eps;
        while (hi - lo > eps) {
            T mid = lo + (hi - lo) / 2;
            f(mid) ? hi = mid : lo = mid + eps;
        }
        return f(lo) ? lo : hi + eps;
    }
    
    template<typename T, typename U>
    T last_double_true(T lo, T hi, U f) {  // If f(X) is not satisfied in range [lo, hi], returns (lo - eps);
        lo -= eps;
        while (hi - lo > eps) {
            T mid = lo + (hi - lo) / 2;
            f(mid) ? lo = mid : hi = mid - eps;
        }
        return f(lo) ? lo : lo - eps;
    }
}

using namespace binary_search_operations;