//Christmas Party
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxA = 2e6, M = 1e9+7;
ll iv[mxA+1], f1[mxA+1], f2[mxA+2], dp[mxA+1];

int main() {
  iv[1] = 1;
  for (int i = 2; i <= mxA; ++i)
    iv[i] = M - M / i * iv[M%i] % M;
  f1[0] = f2[0] = 1;
  for (int i = 1; i <= mxA; ++i) {
    f1[i] = f1[i-1] * i % M;
    f2[i] = f2[i-1] * iv[i] % M;
  }
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = ((i - 1) * (dp[i-1]) + (i - 1) * dp[i-2]) % M;
  }
  cout << dp[n];
}
