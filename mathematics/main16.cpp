//Candy Lottery
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxN = 100;
int n, k;
double a[mxN+1];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    a[i] = 1;
    for (int j = 0; j < n; ++j) 
      a[i] *= (double)i / k;
  }
  double ans = 0;
  for (int i = k; i; --i) {
    a[i] -= a[i-1];
    ans += i * a[i];
  }
  cout << fixed << setprecision(6) << ans;
}
