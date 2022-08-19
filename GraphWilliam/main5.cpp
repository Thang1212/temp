//Teleporters Path
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5, mxM = 2e5;
int n, m, eu[mxM], ev[mxM], ind[mxN], out[mxN];
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
		ans.push_back(u);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		ind[ev[i]]++;
		out[eu[i]]++;
	}

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			if (ind[i] + 1 != out[i]) {
				cout << "IMPOSSIBLE";
				return 0;
			}
		} else if (i == n-1) {
			if (ind[i] != out[i] + 1) {
				cout << "IMPOSSIBLE";
				return 0;
			}
		} else if (ind[i] != out[i]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}

	dfs();

	if (ans.size() != m) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	reverse(ans.begin(), ans.end());
	for (int a:ans)
		cout << a+1 << " ";
	cout << n;
}
