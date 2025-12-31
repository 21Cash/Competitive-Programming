#include <set>
#include <map>
#include <utility>
using namespace std;

// -------- For set<int> --------

// Returns the largest element in s that is <= x.
pair<bool, set<int>::iterator> get_largest_less_or_eq_x(set<int> &s, int x) {
    auto it = s.upper_bound(x); 
    if (it == s.begin()) {      
        return {false, s.end()};
    }
    --it;                      
    return {true, it};
}

// Returns the largest element in s that is < x.
pair<bool, set<int>::iterator> get_largest_less_than_x(set<int> &s, int x) {
    auto it = s.lower_bound(x);
    if (it == s.begin()) {    
        return {false, s.end()};
    }
    --it;                    
    return {true, it};
}

// Returns the smallest element in s that is >= x.
pair<bool, set<int>::iterator> get_smallest_greater_or_eq_x(set<int> &s, int x) {
    auto it = s.lower_bound(x);
    if (it == s.end()) {       
        return {false, s.end()};
    }
    return {true, it};
}

// Returns the smallest element in s that is > x.
pair<bool, set<int>::iterator> get_smallest_greater_than_x(set<int> &s, int x) {
    auto it = s.upper_bound(x); 
    if (it == s.end()) {        
        return {false, s.end()};
    }
    return {true, it};
}

// ------------------------------------------



// -------- For map<int, int> --------

// Returns the pair in m with the largest key that is <= x.
pair<bool, map<int,int>::iterator> get_largest_less_or_eq_x(map<int,int> &m, int x) {
    auto it = m.upper_bound(x); 
    if (it == m.begin()) {       
        return {false, m.end()};
    }
    --it;                     
    return {true, it};
}

// Returns the pair in m with the largest key that is < x.
pair<bool, map<int,int>::iterator> get_largest_less_than_x(map<int,int> &m, int x) {
    auto it = m.lower_bound(x); 
    if (it == m.begin()) {     
        return {false, m.end()};
    }
    --it;                     
    return {true, it};
}

// Returns the pair in m with the smallest key that is >= x.
pair<bool, map<int,int>::iterator> get_smallest_greater_or_eq_x(map<int,int> &m, int x) {
    auto it = m.lower_bound(x);
    if (it == m.end()) {        
        return {false, m.end()};
    }
    return {true, it};
}

// Returns the pair in m with the smallest key that is > x.
pair<bool, map<int,int>::iterator> get_smallest_greater_than_x(map<int,int> &m, int x) {
    auto it = m.upper_bound(x); 
    if (it == m.end()) {       
        return {false, m.end()};
    }
    return {true, it};
}

// ----------------------------------------