// --------------------------------------------------- Debug Template -------------------------------------------------------------

#define new_line_count 2 // How many new lines after each debug ?
#define tc_num_stream std::cout 
#define d_stream std::cout

#ifdef CASH_LOCAL
#define DEBUG_OUT
#define DEBUG_TC_NUM
#endif 

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

// #undef DEBUG_TC_NUM
// #undef DEBUG_OUT

#ifdef DEBUG_OUT
#define dout d_stream
#define db(x...) {d_stream << "["; _print(x); }
#define dbg(x...) { d_stream << "[" << #x << "] = ["; _print(x); } 
#define f_dbg(x...) { d_stream << "[" << __func__ << ":" << (__LINE__) << " [" << #x << "] = ["; _print(x);  } 
#endif 

// --------------------------------------------------------------------------------------------------------------------------------