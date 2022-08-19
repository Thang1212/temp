//Exponentiation II
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int M = 1e9+7;

ll pM(ll b, ll p, ll m = 0) {
  ll r = 1;
  while (p) {
    if (p&1)
      r = r * b % m;
    b = b * b % m;
    p /= 2;
  }
  return r;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pM(a, pM(b, c), M) << "\n";
  }
}
