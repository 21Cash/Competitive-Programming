#define MAXLEN 1000010

constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b){
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init(){
    base_pow[0] = 1;
    for (int i = 1; i < MAXLEN; i++){
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash {
    int64_t hash_value;

    PolyHash(const vector<char>& ar) {
        if (!base_pow[0]) init();

        int n = ar.size();
        assert(n < MAXLEN);
        hash_value = 0;

        for (int i = 1; i <= n; i++) {
            hash_value = modmul(hash_value, base) + ar[i - 1] + 997;
            if (hash_value >= mod) hash_value -= mod;
        }
    }

    PolyHash(const char* str) : PolyHash(vector<char>(str, str + strlen(str))) {}

    PolyHash(const std::string& str) : PolyHash(vector<char>(str.begin(), str.end())) {}

    uint64_t get_hash() {
        return hash_value;
    }
};