#include <bits/stdc++.h>
using namespace std;

int h;

int main() {
	cout << "Nhap canh tam giac can: ";
	cin >> h;
	cout << "\n";

	int out = h - 1, in = 0;
	char asterisk = '*';
	char space = ' ';
	for (int i = 0; i < h; ++i) {
		// Last line
		if (i == h - 1) {
			for (int l = 0; l < 2 * h - 1; ++l)
				printf("%c%c", asterisk, space);
		}
		else {
			int j = 2 * out, k = 2 * in; 
			while (j--)
				printf("%c", space);
			printf("%c", asterisk);

			if (in == 0) {
				printf("\n");
				--out, ++in;
				continue;
			}
			else {
				printf("%c", space);
				while (k--) {
					if (k == 0)
						break;
					printf("%c%c", space, space);
				}
				printf("%c", asterisk);
			}
			printf("\n");
			--out, ++in;
		}
	}

	return 0;
}
