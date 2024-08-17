vector<ll> pref_sum(A.size() + 1);
pref_sum[0] = 0;

for(int i = 1; i <= (int) A.size(); i++) {
	pref_sum[i] = pref_sum[i - 1] + A[i - 1];
}

auto query_sum = [&] (int l_index, int r_index) {
	return pref_sum[r_index + 1] - pref_sum[l_index];
};