#include <bits/stdc++.h>
using namespace std;

const int row = 4, col = 4;
int arr[row][col] = {{1, 2, 3, 4},
					 {5, 6, 7, 8},
					 {9, 10, 11, 12},
					 {13, 14, 15, 16}};

void printMat(int mat[][col]) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}

void spiralMat() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			pq.push(arr[i][j]);
		}
	}
	
	int n = row, m = col;
	int currCol = 0, currRow = 0;
	int result[row][col];
	int previous;
	while (pq.size() && currCol < n && currRow < m) {
		for (int i = currCol; i < m; ++i) {
			int u = pq.top();
			pq.pop();
			result[currRow][i] = u;
		}
		++currRow;

		for (int i = currRow; i < n; ++i) {
			int u = pq.top();
			pq.pop();
			result[i][n-1] = u;
		}
		--m;

		if (currRow < n) {
			for (int i = m-1; i >= currCol; --i) {
				int u = pq.top();
				pq.pop();
				result[n-1][i] = u;
			}
			--n;
		}

		if (currCol < m) {
			for (int i = n-1; i >= currRow; --i) {
				int u = pq.top();
				pq.pop();
				result[i][currCol] = u;
			}
			++currCol;
		}
					
	}
	printMat(result);
}


int main() {
	spiralMat();
}
