// O(3**(n/3))
const int MAXN = 50;
bool edg[MAXN][MAXN];
bool used[MAXN];
int cnt=0,bst=0,n;
void bc(int i) {
	if(i >= n) {
		bst = max(bst,cnt);
		return;
	}
	bool flag = false;
	rep(j,0,i) {
		if(used[j] && !edg[i][j]) {
			flag = true;
			break;
		}
	}
	if(!flag) { // can use
		used[i] = true;
		cnt++;
		bc(i+1);
		cnt--;
	}
	if(cnt+n-i > bst) {
		used[i] = false;
		bc(i+1);
	}
}
