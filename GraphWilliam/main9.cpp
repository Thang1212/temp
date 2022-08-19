//Police Chase
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 500, mxM = 1e3;
int n, m, d[mxN], p[mxN];
vector<int> adj[mxN];
bool vis[mxN];

struct edge {
	int u, v, rev, cap;
} e[2*mxM];

void dfs1(int u = 0) {
	vis[u] = 1;
	for (int i:adj[u]) 
		if (e[i].cap && !vis[e[i].v])
			dfs1(e[i].v);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b, --a, --b;
		c = 1;
		e[2*i] = {a, b, 2*i+1, c};
		e[2*i+1] = {b, a, 2*i, c};
		adj[a].push_back(2*i);
		adj[b].push_back(2*i+1);
	}

	ll f = 0;
	while (1) {
		memset(d, 0x3f, sizeof(d));
		d[0] = 0;
		queue<int> qu;
		qu.push(0);
		while (qu.size()) {
			int u = qu.front();
			qu.pop();
			for (int i:adj[u]) {
				if (e[i].cap && d[e[i].v] > 1e9) {
					d[e[i].v] = d[u] + 1;
					p[e[i].v] = i;
					qu.push(e[i].v);
				}
			}
		}

		if (d[n-1] > 1e9)
			break;
		int mf = 1e9, u = n-1;

		while (u) {
			mf = min(mf, e[p[u]].cap);
			u = e[p[u]].u;
		}

		f += mf;
		u = n-1;

		while (u) {
			e[p[u]].cap -= mf;
			e[e[p[u]].rev].cap += mf;
			u = e[p[u]].u;
		}
	}

	cout << f << "\n";
	dfs1();

	for (int i = 0; i < 2*m; ++i) 
		if (!e[i].cap && vis[e[i].u] && !vis[e[i].v]) 
			cout << e[i].u + 1 << " " << e[i].v + 1 << "\n";

	return 0;
}
