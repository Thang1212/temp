//Maximum subarray sum
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n;

int main() {
	cin >> n;
	//msf: max so far
	ll ans = -1e18, msf = -1e18;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		msf = max((ll)a, msf+a);
		ans = max(ans, msf);
	}
	cout << ans;
}
