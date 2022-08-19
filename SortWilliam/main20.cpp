//Sliding Cost
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN = 2e5;
int n, k;
ll a[mxN], sb, st;
ar<int, 2> med = {-1};
set<ar<int, 2>> bot, top;

void fix() {
	int m = 1 + bot.size() + top.size();
	if (bot.size() < (m-1) / 2) {
		bot.insert(med);
		sb += med[0];
		med = *top.begin();
		top.erase(med);
		st -= med[0];
	}
	if (bot.size() > (m-1) / 2) {
		top.insert(med);
		st += med[0];
		med = *--bot.end();
		bot.erase(med);
		sb -= med[0];
	}
}

void add(ar<int, 2> x) {
	if (med[0] == -1) {
		med = x; 
		return;
	}
	if (x < med) 
		bot.insert(x), sb += x[0];
	else 
		top.insert(x), st += x[0];
	fix();
}

void rem(ar<int, 2> x) {
	if (x == med) {
		med = *top.begin();
		top.erase(med);
		st -= med[0];
	}
	else if (x < med) 
		bot.erase(x), sb -= x[0];
	else 
		top.erase(x), st -= x[0];
	fix();
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) 
		cin >> a[i];

	if (k == 1) {
		for (int i = 0; i < n; ++i)
			cout << 0 << " ";
		return 0;
	}

	for (int i = 0; i < k-1; ++i)
		add({(int)a[i], i});
	for (int i = k-1; i < n; ++i) {
		add({(int)a[i], i});
		cout << st - med[0] * (ll) top.size() + med[0] * (ll) bot.size() - sb << " ";
		rem({(int)a[i-k+1], i-k+1});
	}

}
