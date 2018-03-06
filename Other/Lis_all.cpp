// return array for index i, the length of lis for i.
vector<int> lis_all(const vector<int> &a) {
	int n = a.size();
	vector<int> dp(n + 1, inf);
	dp[0] = -1;
	int l = 0, lo, hi, mid;
	vector<int> rtn;
	for (const auto &i : a) {
		lo = 0, hi = l;
		while (lo < hi) {
			mid = (lo + hi + 1) / 2;
			if (dp[mid] >= i) hi = mid - 1;
			else lo = mid;
		}
		l = max(l, ++lo);
		dp[lo] = i;
		rtn.push_back(lo);
	}
	return rtn;
}
