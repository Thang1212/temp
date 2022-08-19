//Creating String II
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxA = 1e6, M = 1e9+7;
ll iv[mxA+1], f1[mxA+1], f2[mxA+2];

int main() {
  int n;
  iv[1] = 1;
  for (int i = 2; i <= mxA; ++i)
    iv[i] = M - M / i * iv[M%i] % M;
  f1[0] = f2[0] = 1;
  for (int i = 1; i <= mxA; ++i) {
    f1[i] = f1[i-1] * i % M;
    f2[i] = f2[i-1] * iv[i] % M;
  }
  string s;
  cin >> s;
  int c[26] = {};
  for (char d:s) 
    c[d-'a']++;
  ll ans = f1[s.size()];
  for (int i = 0; i < 26; ++i)
    ans = ans * f2[c[i]] % M;
  cout << ans;
}
