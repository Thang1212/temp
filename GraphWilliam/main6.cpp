//Hamiltonian Flights
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 20, M = 1e9+7;
int n, m; 
ll dp[1<<mxN][mxN];
ll adj[mxN][mxN];

int main() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b, --a, --b;
		++adj[a][b];
	}

	dp[1][0] = 1;
	for (int i = 2; i < 1<<n; ++i) {
		if (i>>(n-1) & 1 && i != (1<<n)-1)
			continue;
		for (int j = 0; j < n; ++j) {
			if (i>>j & 1) {
				int i2 = i^1 << j;
				for (int k = 0; k < n; ++k) {
					if (i2>>k & 1 && adj[k][j]) {
						dp[i][j] += adj[k][j] * dp[i2][k];
					}
				}
				dp[i][j] %= M;
			}
		}
	}

	cout << dp[(1<<n)-1][n-1];
}

