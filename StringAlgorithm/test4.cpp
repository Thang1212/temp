#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;

vector<int> manacher_odd(string t) {
	int n = t.size();	
	t += "!" + t + "*";
	vector<int> p(n + 2);
	int l = 0, r = -1;
	for (int i = 0; i <= n; ++i) {
		p[i] = max(0, min(r - i, p[l+(r-i)]));

		while (t[i-p[i]] == t[i+p[i]])
			++p[i];

		if (i + p[i] > r)
			l = i - p[i], r = i + p[i];
	}
	return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string t) {
	string r;
	for (char c:t)
		r += string("#") + c;
	vector<int> res = manacher_odd(r + string("#"));
	return vector<int>(begin(res) + 1, end(res) - 1);
}

int main() {
	string s;
	cin >> s;

	vector<int> p = manacher(s);
	vector<int> ans{0};
	for (int i = 0; i < p.size(); ++i) 
		ans = max(ans, {p[i] - 1, (p[i] - 1) % 2 == 0 ? (i - p[i]) / 2 + 1 : i / 2 - (p[i] - 1) / 2});
	for (int i = ans[1]; i < ans[1] + ans[0]; ++i)
		cout << s[i];
}
