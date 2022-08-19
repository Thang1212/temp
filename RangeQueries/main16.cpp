//Range Queries and Copies
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n, q, t[mxN], sts = 1;
vector<int> v{0};

struct node {
	int lc, rc;
	ll s;
} st[mxN*40];

void upd(int &i, int l1, int x, int l2 = 0, int r2 = n-1) {
	st[sts].lc = st[i].lc;
	st[sts].rc = st[i].rc;
	st[sts].s = st[i].s + x;

	cout << "sts value: " << sts << "\n";
	cout << "i value: " << i << "\n";
	cout << "(sts) st[" << sts << "].lc value: " << st[sts].lc << "\n";
	cout << "(i) st[" << i << "].lc value: " << st[i].lc << "\n";
	cout << "(sts) st[" << sts << "].rc value: " << st[sts].rc << "\n";
	cout << "(i) st[" << i << "].rc value: " << st[i].rc << "\n";
	cout << "\n-------------------done----------------------\n";


	i = sts++;
	if (l2 == r2) 
		return;
	int m2 = (l2 + r2) / 2;
	if (l1 <= m2)
		upd(st[i].lc, l1, x, l2, m2);
	else 
		upd(st[i].rc, l1, x, m2 + 1, r2);
}

ll qry(int i, int l1, int r1, int l2 = 0, int r2 = n-1) {
	if (l1 <= l2 && r2 <= r1) 
		return st[i].s;
	int m2 = (l2 + r2) / 2;
	return (l1 <= m2 ? qry(st[i].lc, l1, r1, l2, m2) : 0) + (m2 < r1 ? qry(st[i].rc, l1, r1, m2 + 1, r2) : 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) 
		cin >> t[i], upd(v[0], i, t[i]);

	while (q--) {
		int qt;
	   	cin >> qt;
   		if (qt == 1) {
			int k, a, x;
			cin >> k >> a >> x, --k, --a;
			upd(v[k], a, x - qry(v[k], a, a));
		} else if (qt == 2) {
			int k, a, b;
			cin >> k >> a >> b, --k, --a, --b;
			cout << qry(v[k], a, b) << "\n";
		} else {
			int k;
			cin >> k, --k;
			v.push_back(v[k]);
		}
	}

	//cout << "st.lc value: ";
	//for (int i = 0; i <= 17; ++i) 
		//cout << st[i].lc << " ";
	//cout << "\n";

	//cout << "st.rc value: ";
	//for (int i = 0; i <= 17; ++i) 
		//cout << st[i].rc << " ";
	//cout << "\n";

	//cout << "st.s value: ";
	//for (int i = 0; i <= 17; ++i) 
		//cout << st[i].s << " ";
	//cout << "\n";
}
