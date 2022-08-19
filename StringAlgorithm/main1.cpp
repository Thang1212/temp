//Word Combinations
#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e3, mxM = 1e6, M = 1e9+7;
int n, dp[mxN+1], k;
string s[mxM], t;

//Aho-Corasick algorithm

//de: the depth of the node

//sl: suffix link (link the word between 2 branches)
//(sl) index: amount of words in a trie
//(sl) value: order of braches that connect each others

//ol: maybe output link (stores indexes of all words that end at current state)

//d: maybe distance (we store next state for current state and character) (state means things in queue)
struct {
	int c[mxM+1][26], d[mxM+1][26], de[mxM+1], sl[mxM+1], ol[mxM+1], m = 1;

	//Creating Trie Structure
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
					//Because distance stores the next state of current state (not know what I'm talking)
					//So suffix link of v will be previous suffix link of u
					sl[v] = d[sl[u]][i];
					//Issue with suffix link
					if (!ol[v]) 
						ol[v] = ol[sl[v]];
					d[u][i] = v;
					qu.push(v);
				} else 
					//Issue with suffix link
					d[u][i] = d[sl[u]][i];
			}
		}
	}

} ac;

int main() {
	cin >> t >> k;
	n = t.size();
	dp[0] = 1;
	for (int i = 0; i < k; ++i)
		cin >> s[i], ac.ins(s[i]);
	ac.ac();
	int u = 0;
	for (int i = 1; i <= n; ++i) {
		u = ac.d[u][t[i-1]-'a'];
		int v = ac.ol[u];
		while (v) {
			//Count how many way we are able to create words
			//i - ac.de[v]: kind of make senses
			//Imagine depth of v is a word and the other of i may be another word
			dp[i] = (dp[i] + dp[i-ac.de[v]]) % M;
			//If don't have suffix link. It will end 
			//Because there are no combination or not able to create new string
			v = ac.ol[ac.sl[v]];
		}
	}
	//Why we don't see any max() here, but choose the last dp for the answer
	//Maybe because we kind of add on
	//The last v will help many words that have suffix link (create more word)
	cout << dp[n];
}
