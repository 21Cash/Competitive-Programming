// Returns the overlap interval of [a, b] and [x, y]
pair<ll, ll> intersectionInterval(ll a, ll b, ll x, ll y) {
    ll l = max(a, x);
    ll r = min(b, y);
    
    if (l <= r) {
        return {l, r};
    } 
    
    // No Interval Found
    return {-1, -1};
}