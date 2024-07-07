struct DiffArray {
    vector<ll> A, pref;
    
    void init(int _N) {
        A.resize(_N, 0LL);
        pref.resize(_N + 1, 0LL);
    }
    
    void init(vector<ll> &inititalArray) {
        A = inititalArray;
        pref.resize(inititalArray.size() + 1, 0LL);
    }
    
    DiffArray(vector<ll> &inititalArray) {
        init(inititalArray);
    }
    
    DiffArray() { }
    
    void range_add(int l, int r, ll delta) {
        pref[l] += delta;
        pref[r + 1] -= delta;
    }
    
    vector<ll> getArray() {
        for(int i = 1; i <= A.size(); i++) {
            pref[i] += pref[i - 1];
        }
        for(int i = 0; i < A.size(); i++) {
            A[i] += pref[i];
        }
        return A;
    }
};