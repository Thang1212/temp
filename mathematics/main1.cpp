//Exponentiation
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int M = 1e9+7;

ll modpow(ll a, ll b, ll m) {
	if (b == 0)
		return 1 % m;
	ll ex = modpow(a, b / 2, m);
	ex = (ex * ex) % m;
	if (b&1)
		ex = (ex * a) % m;
	return ex;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << modpow(a, b, M) << "\n";
	}
}
