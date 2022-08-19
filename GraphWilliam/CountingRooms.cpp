#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

// Depth - First - Search 
// Count how many connected component

const int mxN = 1e3;
int n, m;
string s[mxN];

bool e(int i, int j);
void dfs(int i, int j);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (e(i, j)) {
				++ans;
				dfs(i, j);
			}
		}
	}

	cout << ans;
	return 0;
}

// If empty or not 
// Why we count the connected component of the floor not the wall?
// Because floor is stop by wall so we can stop dfs run
bool e(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.';
}

void dfs(int i, int j) {
	// We assign to '#' to announce that this node don't need to visit
	s[i][j] = '#';

	// Go depth to the graph sequencely
	if (e(i - 1, j))
		dfs(i - 1, j);
	if (e(i + 1, j))
		dfs(i + 1, j);
	if (e(i, j - 1))
		dfs(i, j - 1);
	if (e(i, j + 1))
		dfs(i, j + 1);
}
