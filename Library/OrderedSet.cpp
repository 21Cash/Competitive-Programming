#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// order_of_key(K) => Returns number of items < K
// find_by_order(k) => returns iterator to the kth element (0 Based Indexed) 

// Only Unique Values
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll query_range(ordered_set<ll> &os, ll l, ll r) {
    ll lPos = os.order_of_key(l);
    ll rPos = os.order_of_key(r + 1);  
    return rPos - lPos;
}