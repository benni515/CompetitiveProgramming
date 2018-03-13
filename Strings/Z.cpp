vi search_positions(string text, string pattern) {
	string s = pattern+"$"+text;
	int n = s.size(), l = 0, r = 0;
	vi z = vi(n,0);
	rep(i,1,n) {
		if(i > r) {
			l = r = i;
			while(r < n && s[r-l] == s[r]) r++;
			z[i] = r-l; r--;
		} else if(z[i-l] < r - i + 1) z[i] = z[i-l];
		else {
			l = i;
			while(r < n && s[r-l] == s[r]) r++;
			z[i] = r-l;r--; } }
	vi index;
	rep(i,0,n) if(z[i] == pattern.size()) index.pb(i-int(pattern.size())-1);
	return index;
}
