//Longest Palindrome
#include <bits/stdc++.h>
using namespace std;
#define ar array

//Manacher's algorithm

const int mxN = 1e6;
//p: palindrome array
//p array has the same length as character
//(index) p: indicate the position of character
//(value) p: the length of sub-palindrome 
int n, p[2*mxN+3];
string s;
//c: character array
char c[2*mxN+3];

int main() {
	cin >> s;
	n = s.size();
	
	//set weird padding for manacher's algo
	c[0] = '!';
	c[1] = '*';
	for (int i = 0; i < n; ++i) {
		c[2*i+2] = s[i];
		c[2*i+3] = '*';
	}
	c[2*n+2] = '@';

	//d: kind of center of sub-pelindrome 
	int d = 0;
	for (int i = 1; i <= 2*n+2; ++i) {
		//Always update left and right (border of sub-palindrome) after calculating p[i]
		
		//i is out side of current sub-pelindrome
		//update p[i]
		if (i <= d + p[d])
			p[i] = min(p[2*d-i], d + p[d] - i);
		
		//Launch Trivial algorithm
		//for each center position i it tries to increase the answer by 1 until it possible
		while (c[i-p[i]] == c[i+p[i]])
			++p[i];
		--p[i];

		//i + p[i]: seems like right of sub-palindrome
		if (i + p[i] > d + p[d])
			d = i;
	}
	
	ar<int, 2> ans{0};
	for (int i = 0; i < 2*n+2; ++i) 
		ans = max(ar<int, 2>{p[i], (i-p[i])/2}, ans);
	for (int i = ans[1]; i < ans[1] + ans[0]; ++i) 
		cout << s[i];
}
