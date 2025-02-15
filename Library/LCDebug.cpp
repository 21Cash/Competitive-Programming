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