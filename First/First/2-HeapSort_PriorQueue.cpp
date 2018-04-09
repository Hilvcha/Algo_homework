#include<iostream>
#include<vector>
const int MAX_NUM = 999;
using namespace std;

inline
int PARENT(int i) {
	return i / 2;
}

inline
int LEFT(int i) {
	return 2*i;
}

inline
int RIGHT(int i) {
	return 2*i+1;
}


template<class T>
struct HeapArry {
	vector<T> A;
	int heap_size=0;
};


template<class T>
void SwapHeap(HeapArry<T> &A, int i, int j ) {
	T temp = A.A[i];
	A.A[i] = A.A[j];
	A.A[j] = temp;
}
//使以i为顶的子树保持最大堆性质
template<class T>
void MAX_HEAPIFY(HeapArry<T> &A, int i) {
	int left = LEFT(i);
	int right = RIGHT(i);
	int largest = 0;
	if (left<=A.heap_size&&A.A[left]>A.A[i]) {
		largest = left;
	}
	else {
		largest = i;
	}
	if (right<=A.heap_size&&A.A[right]>A.A[largest]) {
		largest = right;
	}
	if (largest != i) {
		SwapHeap(A, i, largest);
		MAX_HEAPIFY(A, largest);
	}
}

template<class T>
void BUILD_MAX_HEAP(HeapArry<T> &A) {
	A.heap_size = A.A.size()-1;
	cout << "!!" << A.heap_size << endl;
	for (int i = (A.A.size()-1) / 2; i > 0; i--) {
		MAX_HEAPIFY(A, i);
	}
}

template<class T>
void HEAPSORT(HeapArry<T> &A) {
	for (int i = A.A.size()-1; i >= 2; i--) {
		SwapHeap(A, 1, i);
		A.heap_size--;
		MAX_HEAPIFY(A, 1);
	}
}

template<class T>
T HEAP_MAXIMUM(const HeapArry<T> &A) {
	return A.A[1];
}

template<class T>
T HEAP_EXTRACT_MAX(HeapArry<T> &A) {
	if (A.heap_size < 1) {
		throw "heap underflow";
	}
	int max = A.A[1];
	A.A[1] = A.A[A.heap_size--];
	MAX_HEAPIFY(A, 1);
	return max;
}

template<class T>
void HEAP_INCREASE_KEY(HeapArry<T> &A, int i, T key) {
	if (key < A.A[i]) {
		throw "new key is smaller than current key";
	}
	A.A[i] = key;
	while (i > 1 && A.A[PARENT(i)] < A.A[i]) {
		SwapHeap(A, i, PARENT(i));
		i = PARENT(i);
	}
}
template<class T>
void MAX_HEAP_INSERT(HeapArry<T> &A, T key) {
	A.heap_size++;
	A.A.push_back(-MAX_NUM);
	HEAP_INCREASE_KEY(A, A.heap_size, key);
}


void print_v(const vector<int> S) {
	for (int i = 1;i!=S.size();i++ ){
		cout << S[i] << ' ';
	}
	cout << endl;
}


int main(void) {
	struct HeapArry<int> A;
	A.A.push_back(0);
	int x;
	while (cin >> x) {
		A.A.push_back(x);
	}
	BUILD_MAX_HEAP(A);
	print_v(A.A);
	cout << HEAP_MAXIMUM(A)<<endl;
	MAX_HEAP_INSERT(A, 233);
	cout << HEAP_EXTRACT_MAX(A) << endl;
	print_v(A.A);
	HEAPSORT(A);

	print_v(A.A);
	system("pause");
	return 0;
}


//
//
//void INSERT(S, x) {
//
//}
//
//void MAXIMUM(S) {
//
//}
//
//void EXTRAXT_MAX(S) {
//
//}
//
//void INCREASE_KEY(S, x, k) {
//
//}
