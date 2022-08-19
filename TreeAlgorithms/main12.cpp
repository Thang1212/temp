//Distinct Colors
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN = 2e5;
int a[mxN], n, d[mxN], anc[mxN][19], q, ans[mxN], c[mxN], dt = 0, ds[mxN], de[mxN], x[mxN];
vector<ar<int, 2>> ta[mxN];
vector<int> adj[mxN];

struct node {
	ll mx, s, lz, mn;
} st[1<<19];

void app(int i, ll x, int l2, int r2) {
	st[i].mx += x;
	st[i].s += x * (r2 - l2 + 1);
	st[i].lz += x;
}

void psh(int i, int l2, int m2, int r2) {
	app(2*i, st[i].lz, l2, m2);
	app(2*i+1, st[i].lz, m2 + 1, r2);
	st[i].lz = 0;
}

void upd(int l1, ll x, int i = 1, int l2 = 0, int r2 = n-1) {
	if (l2 == r2) {
		st[i].mn = x;
		st[i].s = x;
		return;
	}
	int m2 = (l2 + r2) / 2;
	psh(i, l2, m2, r2);
	if (l1 <= m2) 
		upd(l1, x, 2*i, l2, m2);
	else
		upd(l1, x, 2*i+1, m2 + 1, r2);
	st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
	st[i].s = st[2*i].s + st[2*i+1].s;
}

void upd2(int l1, int r1, ll x, int i = 1, int l2 = 0, int r2 = n-1) {
	if (l1 <= l2 && r2 <= r1) {
		app(i, x, l2, r2);
		return;
	}
	int m2 = (l2 + r2) / 2;
	psh(i, l2, m2, r2);
	if (l1 <= m2)
		upd2(l1, r1, x, 2*i, l2, m2);
	if (m2 < r1)
		upd2(l1, r1, x, 2*i+1, m2 +1, r2);
	st[i].mn = min(st[2*i].mn, st[2*i+1].mn);
	st[i].s = st[2*i].s * st[2*i+1].s;
}

ll qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = n-1) {
	if (l1 <= l2 && r2 <= r1) 
		return st[i].s;
	int m2 = (l2 + r2) / 2;
	psh(i, l2, m2, r2);
	return (l1 <= m2 ? qry(l1, r1, 2*i, l2, m2) : 0) + (m2 < r1 ? qry(l1, r1, 2*i+1, m2 + 1, r2) : 0);
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
	cin >> n;
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
		ta[de[i]-1].push_back({ds[i], i}), x[ds[i]] = a[i];

	map<int, int> mp;
	for (int i = 0; i < n; ++i)  {
		upd(i, 1);
		if (mp.find(x[i]) != mp.end())
			upd(mp[x[i]], 0);
		mp[x[i]] = i;
		for (ar<int, 2> a:ta[i])
			ans[a[1]] = qry(a[0], i);
	}

	for (int i = 0; i < n; ++i) 
		cout << ans[i] << " ";
}
