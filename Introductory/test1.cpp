#include <bits/stdc++.h>
using namespace std;
#define ar array

vector<ar<int, 2>> v;

// There are 3 main steps to divide this problems to smaller ones
// This 3 steps not completely solve the problem -> we need to recursive it
// If we move from this rod -> that rod => So the left rod will act like auxiliary
// It means 1, 2 or 3 is able to be auxiliary rod

// Step 1: shift n - 1 disks A -> B 
// Step 2: shift last disk A -> C
// Step 3: shift n - 1 disks B -> C
void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod) {
	if (n == 0)
		return;
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	// Why we put maintain vector here
	// Because this is where the first recursion done (after return)
	v.push_back({from_rod, to_rod});
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
	int n;
	cin >> n;

	towerOfHanoi(n, 1, 3, 2);
	cout << (int)v.size() << "\n";
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << (*it)[0] << " " << (*it)[1] << "\n";

	return 0;
}
