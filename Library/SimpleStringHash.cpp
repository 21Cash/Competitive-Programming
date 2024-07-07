// Simple Hash
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

template<typename T>
uint64_t vector_hash(const vector<T>& ar) {
    if (!base_pow[0]) init();

    int n = ar.size();
    assert(n < MAXLEN);

    uint64_t hash_value = 0;
    for (int i = 0; i < n; i++) {
        hash_value = modmul(hash_value, base) + ar[i] + 997;
        if (hash_value >= hash_mod) hash_value -= hash_mod;
    }

    return hash_value;
}