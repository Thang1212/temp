//Common Divisor
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxA = 1e6;
int c[mxA+1];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++c[x];
  }

  for (int i = mxA; i; --i) {
    int d = 0;
    for (int j = i; j <= mxA; j+=i)
      d += c[j];
    if (d > 1) {
      cout << i;
      break;
    }
  }
}
