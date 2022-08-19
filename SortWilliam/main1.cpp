//Restaurant Customers
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n;

int main() {
	cin >> n;
	set<ar<int, 2>> s;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		//s.insert({2*a, 1});
		//s.insert({2*b+1, -1});
		s.insert({a, 1});
		s.insert({b, -1});
	}
	int ans = 0, c = 0;
	for (ar<int, 2> a:s) {
		c += a[1];
		ans = max(c, ans);
	}
	cout << ans;
}
