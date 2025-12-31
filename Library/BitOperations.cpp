namespace bit_operations {
    bool get_kth_bit(ll src, ll K) { // Returns true/false whether Kth (0-Based) bit is set/unset
        return (src & (1LL << K)) != 0;
    }
    
    bool is_set(ll src, ll K) { // Returns whether kth bit from right is set or not 
        return get_kth_bit(src, K);
    }
    
    ll set_kth(ll src, ll K) { // Sets Kth (0-Based) from right bit
        return src | (1LL << K);
    }
    
    ll unset_bit(ll src, ll K) { // Unsets Kth (0-Based) From right bit
        return src & ~(1LL << K);
    }
    
    ll flip_kth(ll src, ll K) { // Flips Kth (0-Based) from Right bit
        return src ^ (1LL << K);
    }
    
    ll flip_all_bits(ll src) { // Flips all bits
        return ~src;
    }
    
    ll get_all_set(ll K) { // Returns a bitmask where K bits from right are all set
        return (1LL << K) - 1;
    }
};

using namespace bit_operations;