vector<ll> get_divisors(ll x) {
    vector<ll> factors;
    for (ll i = 1; i <= sqrt(x); ++i) 
    if (x % i == 0) {
        factors.push_back(i);
        if (i != x / i) {
            factors.push_back(x / i);
        }
    }
    // To Return sorted, uncomment below line
    sort(factors.begin(), factors.end());
    return factors;
}