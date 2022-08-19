#include <bits/stdc++.h>
using namespace std;
#define ar array

vector<int> manacher_odd(string s) {
	int n = s.size();
	s = "$" + s + "^";
	vector<int> p(n + 2);
	int l = 0, r = -1;
	for (int i = 1; i <= n; ++i) {
		p[i] = max(0, min(r - i, p[l+(r-i)]));

		while (s[i-p[i]] == s[i+p[i]])
			++p[i];

		if (i + p[i] > r) 
			l = i - p[i], r = i + p[i];
	}
	return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
	string t;
	for (auto c:s)
		t += string("#") + c;
	auto res = manacher_odd(t + "#");
	return vector<int>(begin(res) + 1, end(res) - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());

	vector<int> p = manacher(s);
	ar<int, 2> ans{0};
	for (int i = 0; i < 2 * s.size() - 1; ++i) 
		ans = max(ans, {p[i] - 1, (p[i] - 1) % 2 == 0 ? (i - p[i]) / 2 + 1 : i / 2 - (p[i] - 1) / 2});
	for (int i = ans[1]; i < ans[0] + ans[1]; ++i)
		cout << s[i];
}
