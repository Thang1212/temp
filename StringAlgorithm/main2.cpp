//String Matching
// "{{{
#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e3, mxM = 1e6, M = 1e9+7;
string s, t;

//Aho Corasick Algorithm

struct {
	int c[mxM+1][26], d[mxM+1][26], de[mxM+1], sl[mxM+1], ol[mxM+1], m = 1;

	//Build Trie Data structure
	void ins(string s) {
		int u = 0;
		for (char a:s) {
			if (!c[u][a-'a'])
				c[u][a-'a'] = m++;
			u = c[u][a-'a'];
		}
		ol[u] = u;
	}

	//Breadth First Search
	void ac() {
		queue<int> qu;
		qu.push(0);
		while (qu.size()) {
			int u = qu.front();
			qu.pop();
			for (int i = 0; i < 26; ++i) {
				if (c[u][i]) {
					int v = c[u][i];
					de[v] = de[u] + 1;
					sl[v] = d[sl[u]][i];
					if (!ol[v])
						ol[v] = ol[sl[v]];
					d[u][i] = v;
					qu.push(v);
				} else {
					d[u][i] = d[sl[u]][i];
				}
			}
		}
	}

} ac;

int main() {
	cin >> s >> t;
	//Give the pattern to Trie
	ac.ins(t);
	ac.ac();
	int u = 0, ans = 0;
	//Iterate each letter
	for (int i = 0; i < s.size(); ++i) {
		//d: distance (built-in every state and index)
		//d have the same value as ol
		//Analysis every single character of a string
		//if that character don't match pattern character it will give 0
		u = ac.d[u][s[i]-'a'];
		if (u == t.size()) 
			++ans;
	}
	cout << ans;
}
// "}}}
