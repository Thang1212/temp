//Sum of Divisors
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxA = 1e6, M = 1e9+7;

ll c2(ll n) {
  return n % M * ((n - 1) % M) % M * ((M + 1) / 2) % M;
}

int main() {
  ll n, ans = 0;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    ll r = n / (n / i);
    ans += n / i % M * (c2(r+1) - c2(i) + M) % M;
    i = r;
  }
  cout << ans % M;
}
