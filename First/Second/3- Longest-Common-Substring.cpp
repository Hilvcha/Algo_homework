//3．	Longest Common Substring.The following are some instances.
//a)	X: xzyzzyx   Y : zxyyzxz
//b)	X:MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD
//Y : MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG
//
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
static int c[200][200] = {};
static char b[200][200] = {};
int LCS_LENGTH(const string x, const string y) {
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (auto &row : c) {
		for (auto &col : row) {
			col = 0;
		}
	}
	int index = 0;
	int m = x.length();
	int n = y.length();
	int max = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				if (max < c[i][j]) {
					max = c[i][j];
					index = i-1;
				}
				b[i][j] = '\\';

			}
			else {
				c[i][j] = 0;
				b[i][j] = '=';
			}
		}
	}
	for (int i = index-max+1; i <= index ; i++) {
		cout << x[i]<<ends;
	}
	return max;

}
//void display(int i, int j, string x)
//{
//	if (i == 0 || j == 0)
//		return;
//	if (b[i][j] == '\\')
//	{
//		display(i - 1, j - 1, x);
//		cout << x[i - 1];
//	}
//	else{
//		display(i - 1, j, x);
//		display(i, j - 1, x);
//	}
//}

int main(void) {
	string x[] = { "xzyzzyx","MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD" };
	string y[] = { "zxyyzxz","MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG" };
	LCS_LENGTH(x[0], y[0]);

	//display(x[0].length(), y[0].length(), x[0]);
	//system("pause");
	return 0;
}
