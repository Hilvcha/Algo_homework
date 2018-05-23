//4£®	Max Sum.The following is an instance.
//a)	(-2£¬11£¬ - 4£¬13£¬ - 5£¬ - 2)
#include<iostream>
#include<vector>

using namespace std;
int MAX_SUM(vector<int> a) {
	int sum = 0;
	int max = -999;
	for (auto h : a) {
		sum += h;
		if (sum > max) {
			max = sum;
		}
		if (sum < 0) {
			sum = 0;
		}
	}
	return max;
}
int main(void) {
	vector<int> a = { -2,11, -4,13, -5, -2 };
	cout << MAX_SUM(a) << endl;
//	system("pause");
	return 0;
}
