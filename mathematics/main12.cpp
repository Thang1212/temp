//Graph Paths II
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array
#define mat vector<vector<ll>>

const ll inf = 1LL<<60;
const int mxA = 2e6, M = 1e9+7;
const ll M2 = (ll)M * M;
ll iv[mxA+1], f1[mxA+1], f2[mxA+1], dp[mxA+1];

mat cn(int n, int m) {
  return vector<vector<ll>>(n, vector<ll>(m));
}

mat mult(mat &a, mat &b) {
  mat c = cn(a.size(), b[0].size());
  for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < b[0].size(); ++j)
      c[i][j] = inf;
  for (int i = 0; i < a.size(); ++i) {
    for (int k = 0; k < b.size(); ++k) {
      for (int j = 0; j < b[0].size(); ++j) {
        c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return c;
}

int main() {
  iv[1] = 1;
  for (int i = 2; i <= mxA; ++i)
    iv[i] = M - M / i * iv[M%i] % M;
  f1[0] = f2[0] = 1;
  for (int i = 1; i <= mxA; ++i) {
    f1[i] = f1[i-1] * i % M;
    f2[i] = f2[i-1] * iv[i] % M;
  }
 
  int n, m, k;
  cin >> n >> m >> k;
  mat r = cn(n, n), b = cn(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      r[i][j] = b[i][j] = inf; 
    }
    r[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w, --u, --v;
    b[u][v] = min(b[u][v], w + 0ll);
  }
  while (k) {
    if (k&1)
      r = mult(r, b);
    b = mult(b, b);
    k /= 2;
  }
  if (r[0][n-1] >= inf)
    cout << -1;
  else 
    cout << r[0][n-1];
}
