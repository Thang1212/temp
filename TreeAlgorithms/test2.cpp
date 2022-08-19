#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, dp0[mxN], dp1[mxN];
vector<int> adj[mxN];

void dfs(int u = 0, int p = -1) {
	for (int v:adj[u]) {
		if (u == p)
			continue;
		dfs(v, u);
		dp1[u] = max(dp1[u] + max(dp1[v], dp0[v]), dp0[u] + dp0[v] + 1);
		dp0[u] += max(dp1[v], dp0[v]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int p, q;
		cin >> p >> q, --q, --p;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	dfs();
	cout << max(dp0[0], dp1[0]);
}
