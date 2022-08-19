//Subarray sum queries
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long 

const int mxN = 2e5;
int n, q;
ll x[mxN];

struct node {
	ll s, mxl, mxr, mx;
} st[1<<19];

void upd(int l1, ll x, int i = 1, int l2 = 0, int r2 = n-1) {
	if (l2 == r2) {
		st[i].mx = x;
		st[i].s = x;
		st[i].mxl = st[i].mxr = x;
		return;
	}

	int m2 = (l2 + r2) / 2;
	if (l1 <= m2) 
		upd(l1, x, 2*i, l2, m2);
	else 
		upd(l1, x, 2*i+1, m2+1, r2);
	st[i].mx = max({st[2*i].mx, st[2*i+1].mx, st[2*i].mxr + st[2*i+1].mxl});
	st[i].mxl = max(st[2*i].mxl, st[2*i].s + st[2*i+1].mxl);
	st[i].mxr = max(st[2*i+1].mxr, st[2*i+1].s + st[2*i].mxr);
	st[i].s = st[2*i].s + st[2*i+1].s;
}

int qry2(int x, int i = 1, int l2 = 0, int r2 = n-1) {
	if (l2 == r2) 
		return l2;
	int m2 = (l2 + r2) / 2;
	if (st[2*i].mx >= x)
		return qry2(x, 2*i, l2, m2);
	return qry2(x, 2*i+1, m2 + 1, r2);
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> x[i], upd(i, x[i]);
	while (q--) {
		int k;
		cin >> k, --k;
		cin >> x[k];
		upd(k, x[k]);
		cout << max(st[1].mx, 0ll) << "\n";
	}
}
