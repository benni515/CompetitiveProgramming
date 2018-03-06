struct node {
	map<char,node*> down;
	int cnt = 0;
	void add(string j, int at = 0) {
		if(at == j.size()) return;
		if(down.find(j[at]) == down.end()) down[j[at]] = new node;
		down[j[at]]->cnt++;
		down[j[at]]->add(j,at+1);
	}
	int startswith(string j, int at) {
		if(at == j.size()) return cnt;
		if(down.find(j[at]) == down.end()) return 0;
		return down[j[at]]->startswith(j,at+1);
	}
};
