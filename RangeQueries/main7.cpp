//Forest Queries
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, q, a[mxN+1][mxN+1];
string s[mxN];

int main() {
	cin >> n >> q;

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < n; ++j) 
			if (s[i][j] == '*')
				++a[i+1][j+1];
		for (int j = 0; j < n; ++j) 
			a[i+1][j+1] += a[i+1][j];
	}

	for (int i = 0; i < n; ++i) 
		for (int j = 1; j <= n; ++j)
			a[i+1][j] += a[i][j];

	while (q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2, --y1, --x1;
		cout << a[y2][x2] - a[y1][x2] - a[y2][x1] + a[y1][x1] << "\n";
	}
}
