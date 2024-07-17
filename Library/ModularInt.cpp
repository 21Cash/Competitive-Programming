template<int m> struct modular_int {
    
    template <typename T> struct ex_gcd {
        T g, a_coeff, b_coeff;
    };
     
    template <typename T> ex_gcd<T> extended_gcd(T a, T b) {
        T x = a, y = b;
        T ax = 1, ay = 0;
        T bx = 0, by = 1;
        while (x) {
            T k = y / x;
            y %= x; std::swap(x, y);
            ay -= k * ax; std::swap(ax, ay);
            by -= k * bx; std::swap(bx, by);
        }
        return {y, ay, by};
    }
    
    static constexpr int mod = (int) 1e9 + 7;
    static constexpr uint32_t umod = (uint32_t) m;
 
    uint32_t val;
 
    modular_int() : val(0) {}
    modular_int(int64_t x) : val(norm(x)) {}
 
    explicit operator int() const { return val; }
 
    modular_int neg() {
        modular_int res;
        res.val = val ? umod - val : 0;
        return res;
    }
 
    modular_int inv() const {
        ex_gcd res = extended_gcd((int) val, mod);
        return modular_int(res.a_coeff);
    }
    friend modular_int inv(const modular_int& a) {
        return a.inv();
    }
 
    modular_int& operator += (const modular_int& rhs) { 
        val += rhs.val; val -= (val >= umod ? umod : 0);
        return *this;
    }
    modular_int& operator -= (const modular_int& rhs) {
        val += umod - rhs.val; val -= (val >= umod ? umod : 0);
        return *this;
    }
    modular_int& operator *= (const modular_int& rhs) {
        val = uint32_t(uint64_t(val) * uint64_t(rhs.val) % umod);
        return *this;
    }
    modular_int& operator /= (const modular_int& rhs) {
        return *this *= rhs.inv();
    }
    modular_int& operator ++ () {
        val = (val == umod - 1 ? 0 : val + 1);
        return *this;
    }
    modular_int* operator -- () {
        val = (val == 0 ? umod - 1 : val - 1);
        return *this;
    }
 
    friend modular_int operator + (const modular_int& lhs, const modular_int& rhs) {
        return modular_int(lhs.val) += rhs; 
    }
    friend modular_int operator - (const modular_int& lhs, const modular_int& rhs) {
        return modular_int(lhs.val) -= rhs; 
    }
    friend modular_int operator * (const modular_int& lhs, const modular_int& rhs) { 
        return modular_int(lhs.val) *= rhs; 
    }
    friend modular_int operator / (const modular_int& lhs, const modular_int& rhs) { 
        return modular_int(lhs.val) /= rhs; 
    }
 
    friend std::ostream& operator << (std::ostream& out, const modular_int& z) { return out << z.val; }
    friend std::istream& operator >> (std::istream& in, modular_int& z) { int v; in >> v; z = modular_int(v); return in; }
 
    friend bool operator == (const modular_int& lhs, const modular_int& rhs) { return lhs.val == rhs.val; };
    friend bool operator != (const modular_int& lhs, const modular_int& rhs) { return lhs.val != rhs.val; };
 
    modular_int pow(int64_t n) const {
        assert(0 <= n);
        modular_int x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
 
    static uint32_t norm(int64_t x) {
        x %= mod; if (x < 0) x += mod;
        return (uint32_t) x;
    } 
};