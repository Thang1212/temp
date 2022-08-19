//Nim game II
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      x ^= a % 4;
    }
    cout << (x ? "first" : "second") << "\n";
  }
}
