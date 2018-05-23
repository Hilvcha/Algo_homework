#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int max_n = 8;

vector<int> array(max_n,0);

bool judge(int n) {
    for (int i = 0; i < n; i++) {
        if (array[i] == array[n] || abs(n - i) == abs(array[n] - array[i])) {
            return false;
        }
    }
    return true;
}

void print()  {
    for (int i = 0; i <array.size(); i++) {
        cout<<array[i]  << " ";
    }
    cout<<endl;
}

void check(int n) {
    if (n == max_n) {
        print();

        return;
    }
    for (int i = 0; i < max_n; i++) {
        array[n] = i;
        if (judge(n)) {
            check(n + 1);
        }
    }
}
int main(){
    check(0);
    return 0;
}
