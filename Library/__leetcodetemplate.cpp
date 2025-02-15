#include <bits/stdc++.h>
using namespace std;

#pragma region

template<class Fun> class y_combinator_result { Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

// --------------------------------------------- Leetcode Debug Template -------------------------------------------------------------

#define new_line_count 2 // How many new lines after each debug ?
#define d_stream std::cout

#define DEBUG_OUT

#ifdef DEBUG_OUT
    #define dout std::cout
    #define db(...) { std::cout << "["; _print(__VA_ARGS__); }
    #define dbg(...) { std::cout << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__); }
    #define f_dbg(...) { std::cout << "[" << __func__ << ":" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__); }
#else
    #define dout if (false) std::cout
    #define db(...)
    #define dbg(...)
    #define f_dbg(...)
#endif

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

// --------------------------------------------------------------------------------------------------------------------------------

using ll = long long;

#define all(C) C.begin(), C.end()
#define rev_all(C) C.rbegin(), C.rend()
#define get_unique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define pop_count(x) __builtin_popcountll(x)

ll POW(ll a, ll b) { return a <= 0 || b < 0 ? 0 : (b == 0 ? 1 : (b % 2 ? a * POW(a, b - 1) : POW(a * a, b / 2))); }
ll GCD(ll x, ll y) { if (x == 0) return y; if (y == 0) return x; return GCD(y, x % y); }
ll LCM(ll a,ll b) { return a * b / GCD(a, b); }
ll ceil_div(ll x, ll y) { assert(y != 0); return (x + y - 1) / y; }
ll floor_div(ll x, ll y) { assert(y != 0); if (y < 0) { y = -y; x = -x; } if (x >= 0) return x / y; return (x + 1) / y - 1; }
bool is_even(ll x) { return (x % 2 == 0); }
bool is_odd(ll x) { return (x % 2 == 1); }
#pragma endregion

