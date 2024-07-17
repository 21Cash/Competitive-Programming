ll get_random(ll L, ll R) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<ll> dis(L, R);
    return dis(gen);
}