#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 1e5;
int n, m;
vector<int> adj[mxN], ans;
bool vis[mxN];

void dfs(int u);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		// Why do we push back 2 times?
		// Undirected graph 
		// So 1 - 2 and 2 - 1 (no direction)
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			// Store all the start point of every DFS rounds
			// Because DFS run deep as possible
			// So the new start will be not connected from other part
			ans.push_back(i);
			dfs(i);
		}
	}

	cout << (int) ans.size() - 1 << "\n";
	for (int i = 0; i < (int) ans.size() - 1; ++i) 
		// We don't important about where the roads start
		// So just build the road from index 0
		cout << ans[0] + 1 << " " << ans[i+1] + 1 << "\n";
	return 0;
}

void dfs(int u) {
	vis[u] = 1;
	for (auto v:adj[u]) {
		if (!vis[v])
			dfs(v);
	}
}
