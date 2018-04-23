#include<iostream>
#include<cstring>
#include<vector>
const int MAX_NUM = 99999;
const int ARRY = 11;
//1го	Matrix - chain product.The following are some instances.
//a)	<3, 5, 2, 1, 10>
//b)	<2, 7, 3, 6, 10>
//c)	<10, 3, 15, 12, 7, 2>
//d)	<7, 2, 4, 15, 20, 5>
int m[ARRY][ARRY] = {};
int s[ARRY][ARRY] = {};
using namespace std;
int LOOKUP_CHAIN(int m[][ARRY], vector<int>p, int i, int j) {
	if (m[i][j] < MAX_NUM) {
		return m[i][j];
	}
	if (i == j) {
		m[i][j] = 0;
	}
	else {
		for (int k = i; k < j; k++) {
			int q = LOOKUP_CHAIN(m, p, i, k) + LOOKUP_CHAIN(m, p, k + 1, j) + p[i - 1] * p[k] * p[j];
			if (q < m[i][j]) {
				m[i][j] = q;
				s[i][j] = k;
			}

		}
	}
	return m[i][j];
}
int MEMOIZED_MATRIX_CHAIN(vector<int> p) {
	int n = p.size() - 1;
	memset(m, 0, sizeof(m));
	for(auto &row:m)
		for (auto &col : row) {
			col = MAX_NUM;
		}
	return LOOKUP_CHAIN(m, p, 1, n);
}
int print_optimal_parens(int i, int j)
{
	if (i == j)
	{
		printf("A");
	}
	else
	{
		printf("(");
		print_optimal_parens(i, s[i][j]);
		print_optimal_parens(s[i][j] + 1, j);
		printf(")");
	}
	return 0;
}

int main1() {
	vector<int> a = { 3, 5, 2, 1, 10 };
	vector<int> b = { 2, 7, 3, 6, 10 };
	vector<int> c = { 10, 3, 15, 12, 7, 2 };
	vector<int> d = { 7, 2, 4, 15, 20, 5 };
	cout << MEMOIZED_MATRIX_CHAIN(a) << endl;
	for (auto &row : m) {
		for (auto col : row) {
			cout << '\t' << col;
		}
		cout << endl;
	}
	print_optimal_parens(1, a.size()-1);
	system("pause");
	return 0;
}