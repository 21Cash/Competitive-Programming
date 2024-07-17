#include <bits/stdc++.h>
using namespace std;

// Library Source - https://github.com/21Cash/Competitive-Programming/tree/main/Library

template<class Fun> class y_combinator_result { Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

// --------------------------------------------------- Debug Template -------------------------------------------------------------

#define DEBUG_OUT
#define DEBUG_TC_NUM

const int new_line_count = 2; // How many new lines after each debug ? 

void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
void _print() { cout << "]" << string(new_line_count, '\n'); }

template <size_t N> void __print(const bitset<N>& x) { cout << x; };
template <typename T> void __print(const T &x);
template <typename T, typename V> void __print(const pair<T, V> &x);
template <typename T> void __print(const T &x);
template <typename T, typename... V> void _print(T t, V... v);
template <typename T, typename V> void __print(const pair<T, V> &x) 
{ cout << '{'; __print(x.first); cout << ", "; __print(x.second); cout << '}'; }
template <typename T> void __print(const T &x) 
{ int f = 0; cout << '{'; for (auto &i : x) cout << (f++ ? ", " : ""), __print(i); cout << "}"; }
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...); }

template<class T> bool ckmin(T&a, const T& b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T& b) { bool B = a < b; a = max(a,b); return B; }

// #undef DEBUG_OUT
#undef DEBUG_TC_NUM

#ifdef DEBUG_OUT
#define dout std::cout
#define db(x...) {cout << "["; _print(x); }
#define dbg(x...) { cout << "[" << #x << "] = ["; _print(x); } 
#define f_dbg(x...) { cout << "[" << __func__ << ":" << (__LINE__) << " [" << #x << "] = ["; _print(x);  } 
#else
#define dout if (false) std::cout
#define db(x...) 
#define dbg(x...)
#define f_dbg(x...)
#endif

// --------------------------------------------------------------------------------------------------------------------------------

using ll = long long;

#define all(C) C.begin(), C.end()
#define get_unique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define to_long_long(vec) vector<long long>((vec).begin(), (vec).end())

ll GCD(ll x, ll y) { if (x == 0) return y; if (y == 0) return x; return GCD(y, x % y); }
ll lcm(ll a,ll b) { return a * b / GCD(a, b); }
ll ceil_div(ll x, ll y) { assert(y != 0); return (x + y - 1) / y; }
ll floor_div(ll x, ll y) { assert(y != 0); if (y < 0) { y = -y; x = -x; } if (x >= 0) return x / y; return (x + 1) / y - 1; }

