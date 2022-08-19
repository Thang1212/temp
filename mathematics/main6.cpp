//Binomial Coefficients
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxA = 1e6, M = 1e9+7;
ll iv[mxA+1], f1[mxA+1], f2[mxA+2];

int main() {
  int n;
  cin >> n;
  iv[1] = 1;
  for (int i = 2; i <= mxA; ++i)
    iv[i] = M - M / i * iv[M%i] % M;
  f1[0] = f2[0] = 1;
  for (int i = 1; i <= mxA; ++i) {
    f1[i] = f1[i-1] * i % M;
    f2[i] = f2[i-1] * iv[i] % M;
  }
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << f1[a] * f2[b] % M * f2[a-b] % M << "\n";
  }
}
