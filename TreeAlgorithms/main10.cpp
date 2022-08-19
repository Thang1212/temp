//Subtree Queries
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;
int n, q, ds[mxN], de[mxN], dt = 0, anc[mxN][19], ans[mxN], d[mxN]; 
ll ft[mxN+1], a[mxN];
vector<int> adj[mxN];

void upd(int i, int x) {
	for (++i; i <= n; i+=i&-i)
		ft[i] += x;
}

ll qry(int i) {
	ll r = 0;
	for (; i; i-=i&-i)
		r += ft[i];
	return r;
}

void dfs(int u = 0, int p = -1) {
	anc[u][0] = p;
	for (int i = 1; i < 19; ++i) 
		anc[u][i] = ~anc[u][i-1] ? anc[anc[u][i-1]][i-1] : -1;
	ds[u] = dt++;
	for (int v:adj[u]) {
		if (v == p) 
			continue;
		d[v] = d[u] + 1;
		dfs(v, u);
	}
	de[u] = dt;
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int p, q;
		cin >> p >> q, --p, --q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	dfs();
	for (int i = 0; i < n; ++i) 
		upd(ds[i], a[i]);
	while (q--) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int s, x;
			cin >> s >> x, --s;
			upd(ds[s], x-a[s]);
			a[s] = x;
		} else {
			int s;
			cin >> s, --s;
			cout << qry(de[s]) - qry(ds[s]) << "\n";
		}
	}
}
