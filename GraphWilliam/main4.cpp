//De Bruijn Sequence
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1<<14, mxM = 1<<15;
int n, m, eu[mxM], ev[mxM];
vector<int> adj[mxN], ans;
bool used[mxM];

void dfs(int u = 0) {
	while (adj[u].size()) {
		int e = adj[u].back();
		adj[u].pop_back();
		if (used[e])
			continue;
		used[e] = 1;
		dfs(eu[e]^ev[e]^u);
		ans.push_back(e);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < 1<<n; ++i) {
		eu[i] = i/2;
		ev[i] = i & ((1 << (n-1)) - 1);
		adj[eu[i]].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		if (adj[i].size() & 1) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}

	dfs();
	for (int a:ans)
		cout << a%2;
	for (int i = 0; i < n-1; ++i) 
		cout << 0;
}
