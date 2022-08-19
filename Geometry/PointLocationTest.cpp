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
};

void testcase() {
	struct P p1, p2, p3;
	p1.read();
	p2.read();
	p3.read();

	p3 -= p1;
	p2 -= p1;

	ll cross_product = p2 * p3;
	if (cross_product < 0) {
		cout << "RIGHT" << "\n";
	} else if (cross_product > 0)
		cout << "LEFT" << "\n";
	else 
		cout << "TOUCH" << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		testcase();
	}

	return 0;
}

