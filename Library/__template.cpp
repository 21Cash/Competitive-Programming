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
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Library Source - https://github.com/21Cash/Competitive-Programming/tree/main/Library

#pragma region Debugger
// --------------------------------------------------- Debug Template -------------------------------------------------------------

#ifdef CASH_LOCAL
#define DEBUG_OUT
#define DEBUG_TC_NUM
#endif 

// #undef DEBUG_TC_NUM
// #undef DEBUG_OUT

#define new_line_count 2 // How many new lines after each debug ?
#define tc_num_stream std::cout 
#define d_stream std::cout

#define dout if (false) std::cout
#define db(x...) 
#define dbg(x...)
#define f_dbg(x...)

void __print(int x) { d_stream << x; }
void __print(long x) { d_stream << x; }
void __print(long long x) { d_stream << x; }
void __print(unsigned x) { d_stream << x; }
void __print(unsigned long x) { d_stream << x; }
void __print(unsigned long long x) { d_stream << x; }
void __print(float x) { d_stream << x; }
void __print(double x) { d_stream << x; }
void __print(long double x) { d_stream << x; }
void __print(char x) { d_stream << '\'' << x << '\''; }
void __print(const char *x) { d_stream << '\"' << x << '\"'; }
void __print(const string &x) { d_stream << '\"' << x << '\"'; }
void __print(bool x) { d_stream << (x ? "true" : "false"); }
void _print() { d_stream << "]" << string(new_line_count, '\n'); }

template <size_t N> void __print(const bitset<N>& x) { d_stream << x; };
template <typename T> void __print(const T &x);
template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename T> void __print(const T &x);
template <typename T, typename... V> void _print(T t, V... v);
template <typename T, typename V> void __print(const pair<T, V> &x) 
{ d_stream << '{'; __print(x.first); d_stream << ", "; __print(x.second); d_stream << '}'; }
template <typename T> void __print(const T &x) 
{ int f = 0; d_stream << '{'; for (auto &i : x) d_stream << (f++ ? ", " : ""), __print(i); d_stream << "}"; }
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) d_stream << ", "; _print(v...); }

template<class T> bool ckmin(T&a, const T& b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T& b) { bool B = a < b; a = max(a,b); return B; }



#ifdef DEBUG_OUT
#define dout d_stream
#define db(x...) {d_stream << "["; _print(x); }
#define dbg(x...) { d_stream << "[" << #x << "] = ["; _print(x); } 
#define f_dbg(x...) { d_stream << "[" << __func__ << ":" << (__LINE__) << " [" << #x << "] = ["; _print(x);  } 
#endif 

// --------------------------------------------------------------------------------------------------------------------------------
#pragma endregion

#pragma region Utilities
using ll =  long long;
using ull = unsigned long long;

#define all(C) C.begin(), C.end()
#define get_unique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define to_long_long(vec) vector<long long>((vec).begin(), (vec).end())
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

ll GCD(ll x, ll y) { if (x == 0) return y; if (y == 0) return x; return GCD(y, x % y); }
ll ceil_div(ll x, ll y) { assert(y != 0); return (x + y - 1) / y; }
ll floor_div(ll x, ll y) { assert(y != 0); if (y < 0) { y = -y; x = -x; } if (x >= 0) return x / y; return (x + 1) / y - 1; }
ll lcm(ll a,ll b) { return a * b / GCD(a, b); }
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
    
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
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