#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

int main() {
	vector<ar<int, 2>> v;
	cout << "vector size value before: " << (int)v.size() << "\n";
	v.push_back({2, 1});
	v.push_back({5, 2});
	v.push_back({4, 2});
	v.push_back({3, 2});
	v.push_back({9, 2});
	v.push_back({8, 2});
	v.push_back({3, 1});
	cout << "vector size value after: " << (int)v.size() << "\n";

	for (auto it = v.begin(); it !=v.end(); ++it)
		cout << (*it)[0] << " " << (*it)[1] << "\n";
	return 0;
}
