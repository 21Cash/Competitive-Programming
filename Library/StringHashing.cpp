// ---------------------------------- String Hashing -------------------------------------------------

#define MAXLEN 1000010

constexpr uint64_t hash_mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (hash_mod / 3) + (hash_mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & hash_mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & hash_mod) + (ret >> 61);
    ret = (ret & hash_mod) + (ret >> 61);
    return ret - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T>& ar){
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0);

        for (int i = 1; i <= n; i++){
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= hash_mod) pref[i] -= hash_mod;
        }
        
        /* Uncomment Below Part if rev_hash is being called */
        // suff.resize(n + 3, 0);
        // for (int i = n; i >= 1; i--){
        //     suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
        //     if (suff[i] >= hash_mod) suff[i] -= hash_mod;
        // }
    }

    PolyHash(const char* str)
        : PolyHash(vector<char> (str, str + strlen(str))) {}
   
    PolyHash(const std::string& str)
        : PolyHash(vector<char>(str.begin(), str.end())) {}

    uint64_t get_hash(int l, int r){
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + hash_mod : h;
    }

    uint64_t rev_hash(int l, int r) {
        if(suff.empty()) {
            cerr << "Uncomment the suffix compute code block in Constructor.\n";
        }
        assert(!suff.empty());
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + hash_mod : h;
    }
};

// --------------------------------------------------------------------------------------------------