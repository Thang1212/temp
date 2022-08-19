#include <bits/stdc++.h>
using namespace std;
#define ll long long

string min_cyclic_string(string s) {
	s += s;
	int n = s.size();
	int i = 0, ans = 0;
	while (i < n / 2) {
		ans = i;	
		int j = i + 1, k = i;
		while (j < n && s[k] <= s[j]) {
			if (s[k] < s[j])
				k = i;
			else 
				++k;
			++j;
		}
		while (i <= k)
			i += j - k;
	}
	return s.substr(ans, n / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string ans = min_cyclic_string(s);
	cout << ans;
}
