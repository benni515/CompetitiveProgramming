const int MaxN = 200000+50;
vii ls;
vi edg[MaxN], INV[MaxN], hold;
bool vis[MaxN];
int n;
void dfs(int at, int &num) {
	vis[at] = true;
	num++;
	iter(it,edg[at]) if(!vis[*it]) dfs(*it,num);
	num++;
	ls.pb(ii(num,at));
}
void dfs2(int at) {
	vis[at] = true;
	hold.pb(at);
	iter(it,INV[at]) if(!vis[*it]) dfs2(*it);
}
vector<vi> scc() {
	int num = 0;
	memset(vis,0,sizeof(vis));
	rep(i,0,n) if(!vis[i]) dfs(i,num);
	memset(vis,0,sizeof(vis));
	sort(ls.rbegin(), ls.rend());
	rep(i,0,n) iter(it,edg[i]) INV[*it].pb(i);
	vector<vi> SCC;
	rep(i,0,n) {
		if(!vis[ls[i].sc]) dfs2(ls[i].sc);
		if(hold.size() != 0) {
			if(hold.size() == 1) {
				iter(it,edg[ls[i].sc]) if(*it == ls[i].sc) SCC.pb(hold);
			} else SCC.pb(hold);
		}
		hold.clear();
	}
	return SCC;
}

