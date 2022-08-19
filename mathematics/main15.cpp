//Moving Robots
#include <bits/stdc++.h>
using namespace std;
#define ar array 
#define ll long long 

const int mxN = 100;
int n;
double dp[mxN][8][8], ans[8][8];

int main() {
  cin >> n;
  for (int i = 0; i < 8; ++i) 
    for (int j = 0; j < 8; ++j) 
      ans[i][j] = 1;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      for (int k = 0; k <= n; ++k)
        for (int i2 = 0; i2 < 8; ++i2)
          for (int j2 = 0; j2 < 8; ++j2)
            dp[k][i2][j2] = 0;
      dp[0][i][j] = 1;
      for (int k = 0; k < n; ++k) {
        for (int i2 = 0; i2 < 8; ++i2) {
          for (int j2 = 0; j2 < 8; ++j2) {
            int nd = (i2 > 0) + (i2 < 7) + (j2 > 0) + (j2 < 7);
            if (i2)
              dp[k+1][i2-1][j2] += dp[k][i2][j2] / nd;
            if (i2 < 7) 
              dp[k+1][i2+1][j2] += dp[k][i2][j2] / nd;
            if (j2)
              dp[k+1][i2][j2-1] += dp[k][i2][j2] / nd;
            if (j2 < 7)
              dp[k+1][i2][j2+1] += dp[k][i2][j2] / nd;
          }
        }
      }
      for (int i2 = 0; i2 < 8; ++i2)
        for (int j2 = 0; j2 < 8; ++j2) 
          ans [i2][j2] *= (1 - dp[n][i2][j2]);
    }
  }
  double a2 = 0;
  for (int i = 0; i < 8; ++i) 
    for (int j = 0; j < 8; ++j) 
      a2 += ans[i][j];
  cout << fixed << setprecision(6) << a2;
}
