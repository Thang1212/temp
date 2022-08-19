//Finding Periods
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 1e6, M = 1000696969, nb = 1, B[nb] = {69};
int n;
string s;
ll pB[nb][mxN+1], h[nb][mxN+1];

ll hs(int l, int r) {
	ll x = h[0][r+1] - h[0][l] * pB[0][r+1-l] % M;
	if (x < 0) 
		x += M;
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();
	for (int i = 0; i < nb; ++i) {
		pB[i][0] = 1;
		for (int j = 1; j <= n; ++j) 
			pB[i][j] = pB[i][j-1] * B[i] % M;
		for (int j = 1; j <= n; ++j)
			h[i][j] = (h[i][j-1] * B[i] + s[j-1] - 'a' + 1) % M;
	}

	for (int i = 1; i <= n; ++i) {
		ll a = hs(0, i-1);
		bool ok = 1;
		for (int j = i; j < n && ok; j+=i) {
			if (j + i <= n) 
				ok &= a == hs(j, j+i-1);
			else 
				ok &= hs(j, n-1) == hs(0, n-1-j);
		}
		if (ok)
			cout << i << " ";
	}
}
