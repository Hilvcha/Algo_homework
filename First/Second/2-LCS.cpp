////2．	Longest Common Subsequence(LCS).The following are some instances.
////a)	X: xzyzzyx   Y : zxyyzxz
////b)	X:MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD
////Y : MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
static char b[200][200] = {};
static int c[200][200] = {};

void LCSeq_LENGTH(const string x, const string y) {
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(b));
	for (auto &row : c) {
		for (auto &col : row) {
			col = 0;
		}
	}
	int m = x.length() ;
	int n = y.length() ;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = '\\'; //左上箭头= =
			}
			else if (c[i - 1][j] > c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 'A';//向上箭头= =
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = '<';//向左箭头！
			}
		}
	}

}
void display(int i, int j, string x)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == '\\')
	{
		display(i - 1, j - 1, x);
		cout<<x[i - 1];
	}
	else if (b[i][j] == 'A') {
		display(i - 1, j, x);
	}
	else if (b[i][j] = '<') {
		display(i, j - 1, x);
	}
}

int main2(void) {
	string x[] = { "xzyzzyx","MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD" };
	string y[] = { "zxyyzxz","MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG" };
	LCSeq_LENGTH(x[1], y[1]);

	display(x[1].length(), y[1].length(), x[1]);
	system("pause");
	return 0;
}
