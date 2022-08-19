#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long

struct P {
	int x, y;

	void read() {
		cin >> x >> y;
	}

	P operator - (const P& b) const {
		return P{x - b.x, y - b.y};
	}

	void operator -= (const P& b) {
		x -= b.x;
		y -= b.y;
	}

	ll operator * (const P& b) const {
		return (ll) x * b.y - (ll) y * b.x;
	}

	ll triangle(const P& b, const P& c) const {
		return (b - *this) * (c - *this);
	}
};

void test_case() {
	P p1, p2, p3, p4;
	p1.read();
	p2.read();
	p3.read();
	p4.read();

	// Check if 2 vectors p1p2 and p3p4 is parallel
	if ((p2 - p1) * (p4 - p3) == 0) {
		// Check if 2 vectors are colinear or not
		// By using cross product
		if (p1.triangle(p2, p3) != 0) {
			cout << "NO\n";
			return;
		}

		// Using bounding box technique
		// In this case we sure that 2 vectors p1p2 and p3p4 parallel and colinear
		// Check if they disjoint or not
		for (int rep = 0; rep < 2; ++rep) {
			if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
				cout << "NO\n";
				return;
			}
			swap(p1, p3);
			swap(p2, p4);
		}
		cout << "YES\n";
		return;
	}

	// If they don't parallel
	for (int rep = 0; rep < 2; ++rep) {
		ll sign1 = (p2 - p1) * (p3 - p1);
		ll sign2 = (p2 - p1) * (p4 - p1);

		if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
			// segment B is strictly on the left or right from line A
			cout << "NO\n";
			return;
		}
		// cross product will detect a intersection point when we stretch the segment to infinity
		// This swap value will hold this situation
		swap(p1, p3);
		swap(p2, p4);
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		test_case();

	return 0;
}
