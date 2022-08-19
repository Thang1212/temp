//Minimal Rotation
//Notice: time limit exceeded
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

//Suffix array
//Counting sort

const int mxN = 1e6;
//m: will be like total number of classes
//sa: suffix array

//cnt: count sort 
//cnt start at 1

//sa2 is for rotation
//sa is for sorting it rotation (lexicographically)
int n, cl[mxN], sa[mxN], sa2[mxN], cl2[mxN], cnt[mxN+1], m;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();
	m = 26;

	for (int i = 0; i < n; ++i) 
		cl[i] = s[i] - 'a' + 1;
	for (int l = 1; l < n; l*=2) {
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < n; ++i)
			++cnt[cl[i]];

		//Building prefix sum
		for (int i = 0; i < m; ++i) 
			cnt[i+1] += cnt[i];

		for (int i = 0; i < n; ++i) 
			sa2[--cnt[cl[(i+l)%n]]] = i;

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i)
			++cnt[cl[i]];

		for (int i = 0; i < m; ++i)
			cnt[i+1] += cnt[i];

		for (int i = n-1; ~i; --i)
			sa[--cnt[cl[sa2[i]]]] = sa2[i];
		m = 0;

		for (int i = 0; i < n; ++i) {
			if (!m || cl[sa[i]] != cl[sa[i-1]] || cl[(sa[i]+l)%n] != cl[(sa[i-1]+l)%n])
				++m;
			cl2[sa[i]] = m;
			if (i == 1 && m == 2) {
				s += s;
				cout << s.substr(sa[0], n);
				return 0;
			}
		}
		memcpy(cl, cl2, 4*n);
	}
	s += s;
	cout << s.substr(sa[0], n);
}
