#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

const int mxN = 2e5;
int n, k, a[mxN];
ll sb = 0, st = 0;
ar<int, 2> med = {-1};
set<ar<int, 2>> top, bot;

void fix();
void add(ar<int, 2> x);
void rem(ar<int, 2> x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	if (k == 1)
		for (int i = 0; i < n; ++i)
			cout << 0 << " ";
	else {
		for (int i = 0; i < k - 1; ++i)
			add({a[i], i});
		for (int i = k - 1; i < n; ++i) {
			add({a[i], i});
			cout << st - (ll)top.size() * (ll)med[0] + (ll)med[0] * (ll)bot.size() - sb << " ";
			rem({a[i-k+1], i - k + 1});
		}
	}
}

void fix() {
	int m = 1 + (int)bot.size() + (int)top.size();
	if ((int)bot.size() < (m - 1) / 2) {
		bot.insert(med);
		sb += (ll)med[0];
		med = *top.begin();
		top.erase(med);
		st -= (ll)med[0];
	} if ((int)bot.size() > (m - 1) / 2) {
		top.insert(med);
		st += (ll)med[0];
		med = *--bot.end();
		bot.erase(med);
		sb -= (ll)med[0];
	}
}

void add(ar<int, 2> x) {
	if (med[0] == -1) {
		med = x;
		return;
	}

	if (x > med) {
		top.insert(x);
		st += (ll)x[0];
	} else {
		bot.insert(x);
		sb += (ll)x[0];
	}
	fix();
}

void rem(ar<int, 2> x) {
	if (med == x) {
		med = *top.begin();
		top.erase(med);
		st -= (ll)med[0];
	} else if (x > med) {
		top.erase(x);
		st -= (ll)x[0];
	} else {
		bot.erase(x);
		sb -= (ll)x[0];
	}
	fix();
}
