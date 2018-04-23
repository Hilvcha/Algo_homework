#include<iostream>
#include<vector>

using namespace std;


template<class T>
void SwapVector(vector<T> &A, int i, int j) {
	T temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

template<class T>
void QUICKSORT(vector<T> &A,int start,int end) {
	if (start < end) {
		int mid = PARTITION(A, start, end);
		QUICKSORT(A, start, mid - 1);
		QUICKSORT(A, mid + 1, end);
	}
}

template<class T>
int PARTITION(vector<T> &A, int start, int end) {
	int left = start, right = end;
	int mid_n = A[end];
	while (left <= right) {
		if (A[right] <mid_n) {
			SwapVector(A, left, right);
			left++;
		}
		else {
			right--;
		}
	}
	//cout << left << ends << right << ends<<end;
	SwapVector(A, right+1, end);
	return right+1;
}

void print_v(const vector<int> S) {
	for (auto a : S) {
		cout << a << ' ';
	}
	cout << endl;
}
int main(void) {
	vector<int> a = {8,4,5,3,2,1,7 };
	QUICKSORT(a, 0, a.size() - 1);
	print_v(a);
	system("pause");
	return 0;
}