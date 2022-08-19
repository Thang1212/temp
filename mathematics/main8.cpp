//Distributiing Apples
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

const int mxA = 2e6, M = 1e9+7;
ll iv[mxA+1], f1[mxA+1], f2[mxA+2];

int main() {
  iv[1] = 1;
  for (int i = 2; i <= mxA; ++i)
    iv[i] = M - M / i * iv[M%i] % M;
  f1[0] = f2[0] = 1;
  for (int i = 1; i <= mxA; ++i) {
    f1[i] = f1[i-1] * i % M;
    f2[i] = f2[i-1] * iv[i] % M;
  }
  int n, m;
  cin >> n >> m;
  cout << f1[n+m-1] * f2[m] % M * f2[n-1] % M;
}
