#include<iostream>
#include<vector>
using namespace std;

int TopK(const int k,const vector<int>A, const vector<int>B,int astart,int aend,int bstart,int bend) {
	//��ģ�������A û���ˣ�����ֻ��Ҫ�ҳ� B �е� k ���Ԫ�أ�Ҳ���� B[k] ע���ҵ�k��ʱ��Ҫ��һ
	if (astart > aend) {
		return B[bend + k - 1];
	}
	if (bstart > bend) {
		return A[bend + k - 1];
	}

	int amid = astart+(aend-astart)/2, bmid = bstart+(bend-bstart)/ 2;
	//��߱պϣ��ұ߿�
	if (A[amid] <= B[bmid]) {
		if (k <= (amid-astart) + (bmid-bstart)+1) {
			return TopK(k, A, B, astart, aend, bstart, bmid-1);
		}
		else {
			return TopK(k-(amid-astart)-1, A, B, amid+1, aend, bstart, bend);
		}
	}
	else {
		if (k <= (amid - astart) + (bmid - bstart) + 1) {
			return TopK(k, A, B, astart, amid-1, bstart, bend);
		}
		else {
			return TopK(k - (bmid - bstart) - 1, A, B, amid, aend, bmid+1, bend);
		}
	}

}

int main(void) {
	vector<int> A = { 1,4,6 };
	vector<int> B = { 2,3,4,5,8,9 };
	int K = 3;
	cout << TopK(K,A, B,0,A.size()-1,0,B.size()-1) << endl;
	system("pause");
}