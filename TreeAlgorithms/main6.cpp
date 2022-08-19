//Company Queries I
#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, d[mxN], anc[mxN][19], q;
vector<int> adj[mxN];

void dfs(int u = 0, int p = -1) {
	anc[u][0] = p;
	for (int i = 1; i < 19; ++i) 
		anc[u][i] = ~anc[u][i-1] ? anc[anc[u][i-1]][i-1] : -1;
	for (int v:adj[u]) {
		if (v == p) 
			continue;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
}

int main() {
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p, --p;
		adj[p].push_back(i);
	}
	dfs();
	while (q--) {
		int x, k;
		cin >> x >> k, --x;
		if (d[x] < k) 
			cout << "-1\n";
		else {
			for (int i = 18; ~i; --i) 
				if (k>>i&1)
					x = anc[x][i];
			cout << x+1 << "\n";
		}
	}
}
