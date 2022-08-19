#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

//i represent for row so it's only able to go Down(1) or Up(-1)
//j represent for column so it's only able to go Left(-1) or Right(1)
const int mxN = 1e3, di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
const char dc[4] = {'D', 'R', 'U', 'L'};

//si, sj, ei, ej: start and end coordinate
int n, m, si, sj, ei, ej, d[mxN][mxN];
//p: parent (store the direction in each coordinate)
string s[mxN], p[mxN];

bool e(int i, int j);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'A')
				si = i, sj = j;
			if (s[i][j] == 'B') {
				ei = i, ej = j;
				// Turn the end coordinate to '.' so we are able to go through this node
				s[i][j] = '.';
			}
		}
		//string(m, 0) function generate p[i] with m empty (0) elements of string 
		//the dimension of p string is like s string
		p[i] = string(m, 0);
	}

	// Shortest Path so we use Breadth - First - Search
	
	//	This queue not sorting at all (this graph is unweighted so sort is no need)
	//	We just sequencely go through the most current (or nearest) node
	queue<ar<int, 2>> qu;
	// Push the starting point
	qu.push({si, sj});
	while ((int) qu.size()) {
		ar<int, 2> u = qu.front();
		qu.pop();
		for (int k = 0; k < 4; ++k) {
			// Choose what direction starting point should go 
			int ni = u[0] + di[k], nj = u[1] + dj[k];
			// If it a wall -> continue
			if (!e(ni, nj))
				continue;
			qu.push({ni, nj});
			// Assign that coordinate to wall so we never visit it again
			s[ni][nj] = '#';
			// Store the index of direction that point should go next
			d[ni][nj] = k;
			// Store the parent or direction
			p[ni][nj] = dc[k];
		}
	}

	if (p[ei][ej]) {
		cout << "YES\n";
		string t;
		// Until starting not meet the ending
		while (si ^ ei || sj ^ ej) {
			t += p[ei][ej];
			// d[ei][ej] ^ 2: it's like tracing the direction back
			// 0 ^ 2 = 2
			// 1 ^ 2 = 3
			// 2 ^ 2 = 0
			// 3 ^ 2 = 1
			int dd = d[ei][ej] ^ 2;
			ei += di[dd];
			ej += dj[dd];
		}
		reverse(t.begin(), t.end());
		cout << t.size() << "\n";
		cout << t;
	} else 
		cout << "NO\n";
	return 0;
}

bool e(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.';
}
