#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

// Breadth - First - Search and Back tracking
// Why do we use BFS?
// Because we want to find the shortest message route
const int mxN = 1e5;
// p: parent
// We use parent as a parent to store, backtracking and store visited nodes
int n, m, p[mxN];
vector<int> adj[mxN], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		// Why do we store node 2 times?
		// Undirected graph
		// 1 - 2: so we can run 2 ways 1 -> 2 and 2 -> 1
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// This queue not sorting at all 
	// Because this is unweighted graph 
	// So we run BFS with the nearest (closest or current) node
	queue<int> qu;
	qu.push(0);
	memset(p, -1, sizeof(p));
	while (qu.size()) {
		int u = qu.front();
		qu.pop();
		for (auto v:adj[u]) {
			if (p[v] < 0) {
				p[v] = u;
				qu.push(v);
			}
		}
	}

	// Our goal is to find the shortest route from 1 -> n - 1
	// If node n - 1 don't have any parent -> so we don't any way to that node
	if (p[n-1] < 0) {
		cout << "IMPOSSIBLE";
	} else {
		// Store the final goal
		int u = n - 1;
		// Backtracking
		while (u) {
			ans.push_back(u);
			u = p[u];
		}
		// Store the first goal
		ans.push_back(0);
		cout << (int) ans.size() << "\n";
		for (int i = (int) ans.size() - 1; ~i; --i)
			cout << ans[i] + 1 << " ";
	}
	return 0;
}

