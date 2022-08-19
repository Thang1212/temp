#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5;
int n;

int main() {
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		auto it = upper_bound(v.begin(), v.end(), a) - v.begin();
		if (it < (int)v.size())
			v[it] = a;
		else 
			v.push_back(a);
	}
	cout << v.size() << "\n";

	cout << "v array: \n";
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	return 0;
}
