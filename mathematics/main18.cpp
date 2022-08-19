//Stick Game
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxN = 1e6;
int n, k;
bool dp[mxN+1];

int main() {
  int n, k;
  cin >> n >> k;
  int p[k];
  for (int i = 0; i < k; ++i)
    cin >> p[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < k; ++j)
      if (p[j] <= i)
        dp[i] |= !dp[i-p[j]];
    cout << (dp[i] ? 'W': 'L');
  }
}
