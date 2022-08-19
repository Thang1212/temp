//Movie Festival
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n;
ar<int, 2> a[mxN];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][1] >> a[i][0];
	}
	sort(a, a+n);
	int ans = 0, l = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i][1] >= l) {
			++ans;
			l = a[i][0];
		}
	}
	cout << ans;
}
