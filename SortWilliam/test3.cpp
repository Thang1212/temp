#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n, t, a[mxN];

int main() {
	cin >> n >> t;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	ll lb = 0, rb = 1e18;
	while (lb < rb) {
		ll mb = (lb + rb) / 2, s = 0;
		for (int i = 0; i < n; ++i)
			s += min((ll) mb / a[i], (ll)1e9);
		if (s >= t)
			rb = mb;
		else 
			lb = mb + 1;
	}
	cout << lb;

	return 0;
}
