//Counting Divisor
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

// lpf: least prime factor
// pfs: prime factors
const int mxA = 1e6;
int lpf[mxA+1];
vector<int> pfs;

int main() {
  for (int i = 2; i <= mxA; ++i) {
    if (!lpf[i]) {
      pfs.push_back(i);
      lpf[i] = i;
    }

    for (int j = 0; j < pfs.size() && pfs[j] <= lpf[i] && i * pfs[j] <= mxA; ++j)
      lpf[i*pfs[j]] = pfs[j];
  }
  int n;
  cin >> n;
  while (n--) {
    map<int, int> mp;
    int x;
    cin >> x;
    while (x > 1) {
      mp[lpf[x]]++;
      x /= lpf[x];
    }
    int ans = 1;
	for (auto p:mp) 
      ans *= (p.second + 1);
    cout << ans << "\n";
  }
}
