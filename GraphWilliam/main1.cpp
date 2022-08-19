//Giant Pizza
#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n, m, who[mxN];
vector<int> adj[mxN], adj2[mxN], st, co;
bool vis[mxN];
char ans[mxN];

//Toping travel
void dfs1(int u) {
	vis[u] = 1;
	for (int v:adj[u]) 
		if (!vis[v]) 
			dfs1(v);
	st.push_back(u);
}

//With the topping Choose or not choose travel
void dfs2(int u, int rt) {
	vis[u] = 0;
	who[u] = rt;
	for (int v:adj2[u]) 
		if (vis[v])
			dfs2(v, rt);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		char c1, c2;
		int u1, u2;
		cin >> c1 >> u1 >> c2 >> u2, --u1, --u2;
		u1 *= 2;
		u2 *= 2;
		if (c1 == '-')
			u1^=1;
		if (c2 == '-')
			u2^=1;
		//even: not fav -  
		//odd: fav +
		adj[u1^1].push_back(u2);
		adj[u2^1].push_back(u1);
	}

	for (int i = 0; i < 2*m; ++i)
		for (int j:adj[i])
			adj2[j].push_back(i);

	for (int i = 0; i < 2*m; ++i) 
		if (!vis[i]) 
			dfs1(i);

	for (int i = 2*m-1; ~i; --i) 
		if (vis[st[i]]) 
			dfs2(st[i], i);

	for (int i = 0; i < m; ++i) {
		if (who[2*i] == who[2*i+1]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		ans[i] = who[2*i] < who[2*i+1] ? '+' : '-';
	}
	
	for (int i = 0; i < m; ++i) 
		cout << ans[i] << " ";
	return 0;
}
