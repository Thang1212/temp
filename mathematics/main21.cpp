//Stair Game check depth first search
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ar array

map<vector<int>, bool> mp;

bool dfs(vector<int> p) {
  if (mp.find(p) == mp.end()) {
    for (int i = 0; i < p.size(); ++i) {
      if (!p[i])
        continue;
      for (int j = 1; j <= p[i]; ++j) {
        vector<int> p2 = p;
        p2[i] -= j;
        if (!p2.back()) 
          p2.pop_back();
        if (i)
          p2[i-1] += j;
        mp[p] |= !dfs(p2); 
      }
    }
  }
  return mp[p];
}

int main() {
  mp[{}] = 0;
  for (int i = 0; i <= 5; ++i) 
    for (int j = 0; j <= 5; ++j) 
      for (int k = 0; k <= 5; ++k)
        for (int l = 0; l <= 5; ++l)
          if(dfs({i, k, j, l}) != (i != j))
            cout << i << " " << j << " " << k << " " << l << endl;
}
