//Inversion Probability
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxN = 100;
int n, a[mxN];

int main() {
  cin >> n;
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < i; ++j) {
      int c = min(a[i], a[j]) * (min(a[i], a[j]) - 1) / 2;
      if (a[j] > a[i])
        c += (a[j] - a[i]) * a[i];
      ans += (double)c / (a[j] * a[i]);
    }
  }
  cout << fixed << setprecision(6) << ans;
}
