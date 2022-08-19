//Stair Game 
#include <bits/stdc++.h>
using namespace std;
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 0; 
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      if (i&1)
        x ^= p;
    }
    cout << (x ? "first" : "second") << "\n";
  }
}
