#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Persistent Segment Tree

const int mxN = 2e5;
//sts: maybe segment tree start
//Because William implement segment tree 1 base-indexed
int n, q, t[mxN], sts = 1;
//vector here will help us create new trees by push more things
//(index): number of creating trees
//(value): the size of modify history of k-th array
vector<int> v{0};

//Why choose this data structure
//They help us:
//1. Store modification history
//2. Able to create new trees based on previous trees
//3. Modify them independently

struct node {
	int rc, lc;
	ll s;
} st[mxN*40];
//mxN*40: just make sure there are enough space (have no idea)

//Use pointer &i here (change the value of vector efficiently)
void upd(int &i, int l1, int x, int l2 = 0, int r2 = n-1) {
	//These things I have no idea	
	//But maybe it store modification history of a tree
	st[sts].lc = st[i].lc;
	st[sts].rc = st[i].rc;

	//Sum: add previous with current
	st[sts].s = st[i].s + x;

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
	cin >> n >> q;

	for (int i = 0; i < n; ++i)	
		cin >> t[i], upd(v[0], i, t[i]);

	while (q--) {
		int qt;
		cin >> qt;
		if (qt == 1) {
			int k, a, x;
			cin >> k >> a >> x, --k, --a;
			//x - qry(v[k], a, a): because we add on or minus a value that makes value a -> x
			upd(v[k], a, x - qry(v[k], a, a));
		}
		else if (qt == 2) {
			int k, a, b;
			cin >> k >> a >> b, --k, --a, --b;
			cout << qry(v[k], a, b) << "\n";
		}
		else {
			int k;
			cin >> k, --k;
			//Creating new trees
			//But turned out it just copy the previous
			//So we push v[k]
			v.push_back(v[k]);
		}
	}
}
