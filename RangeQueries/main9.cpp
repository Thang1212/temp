//List removals
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ar array
#define ll long long

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n;
	oset<ar<int, 2>> s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert({i, x});
	}

	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p, --p;
		auto it = s.find_by_order(p);
		cout << (*it)[1] << " ";
		s.erase(it);
	}
}
