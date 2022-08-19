#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	double dx, dy;
	cin >> dx >> dy >> n;

	vector<int> xp(n), yp(n);
	for (int i = 0; i < n; ++i) 
		cin >> xp[i] >> yp[i];

	vector<int> perm(n);
	for (int i = 0; i < n; ++i) 
		cin >> perm[i], --perm[i];

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);

	sort(order.begin(), order.end(), [&](int i, int j) {
		if (yp[i] != yp[j]) return yp[i] < yp[j];
		return xp[i] < xp[j];
	});

	sort(order.begin() + 1, order.end(), [&](int i, int j) {
		int xa = xp[i] - xp[order[0]];
		int ya = yp[i] - yp[order[0]];
		int xb = xp[j] - xp[order[0]];
		int yb = yp[j] - yp[order[0]];
		return xa * yb - xb * ya > 0;
	});

	vector<int> st;
	for (int i:order) {
		while (st.size() >= 2) {
			ll a = yp[st[st.size()-1]] - yp[st[st.size()-2]];
			ll b = xp[st[st.size()-2]] - xp[st[st.size()-1]];
			ll c = -a * xp[st[st.size()-1]] - b * yp[st[st.size()-1]];
			ll z = a * xp[i] + b * yp[i] + c;
			if (z >= 0) 
				st.pop_back();
			else 
				break;
		}
		st.push_back(i);
	}

	const double eps = 1e-9;
	vector<double> x = {0, dx, dx, 0};
	vector<double> y = {0, 0, dy, dy};

	auto Process = [&](double a, double b, double c) {
		if (x.size() < 3) 
			return;

		x.push_back(x[0]);
		y.push_back(y[0]);	
		vector<double> nx, ny;
		for (int j = 0; j < (int) x.size() - 1; ++j) {
			double z = a * x[j] + b * y[j] + c;
			if (z > -eps) {
				nx.push_back(x[j]);
				ny.push_back(y[j]);
			}
			double z2 = a * x[j+1] + b * y[j+1] + c;
			if (z > eps && z2 < -eps || z < -eps && z2 > eps) {
				double aa = y[j+1] - y[j];
				double bb = x[j] - x[j+1];
				double cc = -aa * x[j] - bb * y[j];
				double d = a * bb - b * aa;
				double dx = (b * cc - c * bb) / d;
				double dy = (c * aa - a * cc) / d;
				nx.push_back(dx);
				ny.push_back(dy);
			}
		}
		swap(x, nx);
		swap(y, ny);
	};

	for (int i = 0; i < n-1; ++i) {
		double a = yp[perm[i+1]] - yp[perm[i]];
		double b = xp[perm[i]] - xp[perm[i+1]];
		double c = -a * xp[perm[i]] - b * yp[perm[i]];
		Process(a, b, c);
	}

	double area = 0;
	for (int i = 0; i < (int) x.size(); ++i) 
		area += (x[i] - x[(i+1)%(int)x.size()]) * (y[i] + y[(i+1)%(int)y.size()]);

	double res = abs(area) * 0.5;
	st.push_back(st[0]);

	for (int i = 0; i < (int) st.size() - 1; ++i) {
		double a = yp[st[i+1]] - yp[st[i]];
		double b = xp[st[i]] - xp[st[i]];
		double c = -a * xp[st[i]] - b * yp[st[i]];
		Process(-a, -b, -c);
	}

	area = 0;
	for (int i = 0; i < (int) x.size(); ++i) 
		area += (x[i] - x[(i+1)%(int)x.size()]) * (y[i] + y[(i+1)%(int)y.size()]);

	res -= abs(area) * 0.5;
	cout << fixed << setprecision(20) << res << "\n";
	return 0;
}
