#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct P {
	int x, y;

	void read() {
		cin >> x >> y;
	}

	P operator - (const P& b) const {
		return P{x - b.x, y - b.y};
	}

	ll operator * (const P& b) const {
		return (ll) (x * b.y) - (y * b.x);
	}

	bool isTriangle(const P& b, const P& c) {
		if ((b - *this) * (c - *this))
			return true;
		else 
			return false;
	}
};

void test_case() {
	struct P p1, p2, p3, p4;
	p1.read();
	p2.read();
	p3.read();
	p4.read();

	if ((p2 - p1) * (p4 - p3) == 0) {
		if (p1.isTriangle(p2, p3)) {
			cout << "NO\n";
			return;
		} else {
			for (int rep = 0; rep < 2; ++rep) {
				if (max(p1.x, p2.x) > min(p3.x, p4.x) || max(p1.y, p2.y) > min(p3.y, p4.y)) {
					cout << "NO\n";
					return;
				}
				swap(p1, p3);
				swap(p2, p4);
			}
			cout << "YES\n";
		}
	} else {
		for (int rep = 0; rep < 2; ++rep) {
			ll sign1 = (p2 - p1) * (p3 - p1);
			ll sign2 = (p2 - p1) * (p4 - p1);
			if ((sign1 > 0 && sign2 > 0) || (sign1 < 0 && sign2 < 0)) {
				cout << "NO\n";
				return;
			}
			swap(p1, p3);
			swap(p2, p4);
		}
		cout << "YES\n";
	}
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
