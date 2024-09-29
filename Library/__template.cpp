#include <algorithm>
#include <climits>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <random>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// "When will 21Cash become a Guardian ??" 

// Author : Sushil L (aka 21Cash), 3rd Year CS
// Library Source - https://github.com/21Cash/Competitive-Programming/tree/main/Library

#ifdef CASH_LOCAL
#include "Debug.hpp"
#endif

#pragma region Utilities

#ifndef DEBUG_OUT
#define dout if (false) std::cout
#define db(x...) 
#define dbg(x...)
#define f_dbg(x...)
#endif

using ll =  long long;
using ull = unsigned long long;

#define all(C) C.begin(), C.end()
#define rev_all(C) C.rbegin(), C.rend()
#define get_unique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define sz(C) (int) C.size() 

template<class Fun> class y_combinator_result { Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

ll POW(ll a, ll b) { return a <= 0 || b < 0 ? 0 : (b == 0 ? 1 : (b % 2 ? a * POW(a, b - 1) : POW(a * a, b / 2))); }
ll GCD(ll x, ll y) { if (x == 0) return y; if (y == 0) return x; return GCD(y, x % y); }
ll LCM(ll a,ll b) { return a * b / GCD(a, b); }
ll ceil_div(ll x, ll y) { assert(y != 0); return (x + y - 1) / y; }
ll floor_div(ll x, ll y) { assert(y != 0); if (y < 0) { y = -y; x = -x; } if (x >= 0) return x / y; return (x + 1) / y - 1; }
bool is_even(ll x) { return (x % 2 == 0); }
bool is_odd(ll x) { return (x % 2 == 1); }
#pragma endregion

const bool single_tc = false;
const long long INF = 1e18;
const long long mod = 1e9 + 7;


void test_case(int tc) {
	
	
	
}

signed main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    
    #ifndef CASH_LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0); 
    #endif
    
    int t = 1;
    if(!single_tc) cin >> t;
    
    for(int i = 1; i <= t; i++) {
        #ifdef DEBUG_TC_NUM
        tc_num_stream << "--------- Case #" << i <<  " ------------\n\n";
        #endif
        
        test_case(i);
        // test_case(i) ? cout << "YES\n" : cout << "NO\n";
        
        #ifdef DEBUG_TC_NUM
        tc_num_stream << "\n";
        #endif
    }
    
    #ifdef DEBUG_TC_NUM
    tc_num_stream << "------------------------------\n";
    #endif    
    
    return 0;
}