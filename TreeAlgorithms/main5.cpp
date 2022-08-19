//Tree Distances II
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n, d[mxN]; 
ll ans[mxN], s[mxN];
vector<int> adj[mxN];

void dfs(int u = 0, int p = -1) {
	s[u] = 1;
	for (int v:adj[u]) {
		if (v == p) 
			continue;
		d[v] = d[u] + 1;
		dfs(v, u);
		s[u] += s[v];
	}
}

void dfs2(int u, ll pd, int p = -1) {
	ans[u] = pd;
	for (int v:adj[u]) {
		if (v == p) 
			continue;
		dfs2(v, pd-s[v]+(n-s[v]), u);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p, q;
		cin >> p >> q, --p, --q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	dfs();
	ll sd = 0;
	for (int i = 0; i < n; ++i) 
		sd += d[i];
	dfs2(0, sd);
	for (int i = 0; i < n; ++i) 
		cout << ans[i] << " ";
}
