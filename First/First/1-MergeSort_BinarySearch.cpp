#include<cstdio>
#include<iostream>
#include<vector>
const int MAX_NUM = 999;
using namespace std;

void print_v(const vector<int> S) {
	for (auto a : S) {
		cout << a<<' ';
	}
	cout << endl;
}

void MERGE(vector<int> &S, int start, int mid, int end) {
//将s分为两部分，并存入新的字符串,加入哨兵
	vector<int> left_str, right_str;
	for (int i = start; i <= mid; i++) {
		left_str.push_back(S[i]);
	}
	left_str.push_back(MAX_NUM);
	for (int i = mid+1; i <= end; i++) {
		right_str.push_back(S[i]);
	}
	right_str.push_back(MAX_NUM);
//按照大小合并到原来的数字集中
	int left_key =0, right_key = 0;
	for (int i = start; i <= end; i++) {
		if (left_str[left_key] <= right_str[right_key]) {
			S[i] = left_str[left_key++];
		}
		else {
			S[i] = right_str[right_key++];
		}
	}
}
void MERGE_SORT(vector<int> &S,int start,int end) {
	if (start<end){
		int mid = (start + end) / 2;
		MERGE_SORT(S, start, mid);
		MERGE_SORT(S, mid+1, end);
		MERGE(S, start, mid, end);
	}
}

int BINARY_SEARCH(const vector<int> S,int x,int start,int end) {
	int mid = start+(end-start) / 2;
	while (start<=end){
		if (x < S[mid]) {
			end = mid - 1;
			mid = start+(end-start) / 2;
		}
		else if (x == S[mid]) {
			return mid;
		}
		else if (x > S[mid]) {
			start = mid + 1;
			mid = start + (end - start) / 2;
		}
	}
	return -1;
}

int main(void) {
	vector<int> S;
	int x = 0,j=0;
	cout << "输入整数集合与x" << endl;
	while (cin >> x) {
		S.push_back(x);
	}
	S.pop_back();
	cout << x << endl;
	MERGE_SORT(S, 0, S.size()-1);
	print_v(S);

	for (int i = 0; i != S.size(); i++) {
		cout << x - S[i] << ends << i << ends << S.size() - 1<<endl;
		j = BINARY_SEARCH(S, x - S[i], i, S.size() - 1);
		if (j!=-1) {
			cout << "存在整数对" << S[i] << "和" << S[j] << "可以组成x:" << x << endl;
		}
	}
	print_v(S);
	system("pause");

}