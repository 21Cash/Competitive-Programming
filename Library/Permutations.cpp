vector<vector<ll>> get_permutations(vector<ll>& arr) {
    vector<vector<ll>> result;
    sort(arr.begin(), arr.end()); 
    do {
        result.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));
    return result;
}