#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; 

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename num_t>
struct ordered_multiset {
    ordered_set<pair<num_t, int> > vals;
    set<pair<num_t, int> > best; /* start at -1 */
    
    /* helper, find the lowest value that represents the element */
    int findbest(num_t val) {
        return (*best.upper_bound(make_pair(val - 1, 0))).second;
    }
    
    /* is element in set */
    bool contains(num_t val) {
        return vals.find(make_pair(val, -1)) != vals.end();
    }
    
    void insert(num_t val) {
        if (contains(val)) { /* already in, update lowest value and insert a new one */
            int loc = findbest(val);
            best.erase(make_pair(val, loc));
            best.insert(make_pair(val, loc - 1));
            vals.insert(make_pair(val, loc - 1));
        } else { /* make lowest value -1 and insert it */
            best.insert(make_pair(val, -1));
            vals.insert(make_pair(val, -1));
        }
    }
    
    void erase(num_t val) { /* erases one */
        if (!contains(val)) return; /* not in */
        num_t loc = findbest(val);
        
        /* remove the element and its best */
        best.erase(make_pair(val, loc));
        vals.erase(make_pair(val, loc));
        if (loc != -1) best.insert(make_pair(val, loc + 1)); /* more elements in set, update best */
    }
    
    // Returns the Number of Elements which are in  range [l, r] inclusive
    ll query_range(ll l, ll r) {
        ll lPos = order_of_key(l);
        ll rPos = order_of_key(r + 1);  
        return rPos - lPos;
    }
    
    /* unmodified functions */
    num_t find_by_order(int k) { return (*vals.find_by_order(k)).first; }
    int order_of_key(num_t k) { return vals.order_of_key(make_pair(k - 1, 0)); }
    auto begin() { return vals.begin(); }
    auto end() { return vals.end(); }
    auto rbegin() { return vals.rbegin(); }
    auto rend() { return vals.rend(); }
    int size() { return vals.size(); }
    void clear() { vals.clear(); best.clear(); }
    int count(num_t k) { return vals.order_of_key({k, 0}) - vals.order_of_key({k - 1, 0}); }
    auto lower_bound(num_t k) { return vals.lower_bound(make_pair(k - 1, 0)); }
    auto upper_bound(num_t k) { return vals.upper_bound(make_pair(k, 0)); }
};

/* -------------- Ordered_Multiset ------------------

int main() {
    ordered_multiset<long long> oms;
    vector<ll> to_ins = {5, 23, 23, 24, 24, 24, 25, 39, 39, 100 };
    
    for(ll x : to_ins) {
        oms.insert(x);
    }

    for(auto [x, _] : oms) { // iterating over ordered multiset 
        cout << x << " ";
    }
    cout<<endl;
    
    cout << oms.find_by_order(2) << endl; // 23
    cout << oms.order_of_key(26) << endl; // 7
    
    cout << oms.count(24) << endl; // 3
    
    cout << oms.lower_bound(24)->first << endl; // use in this way, Output : 24
    
    cout << oms.upper_bound(23)->first << endl; // Use this Way, Output : 24

    return 0;
}

// find_by_order(k) - returns a pointer to the k-th smallest element in the set (zero-indexed)
// order_of_key(k) - returns the number of elements in the set less than k (if k is in the set, this is the index of it)

-------------- Ordered_Multiset -----------------------

*/