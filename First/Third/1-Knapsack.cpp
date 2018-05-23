#include <iostream>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

float fractional_knapsack(int max_size, const vector<int> &value, const vector<int> &weight,const vector<float> &vw) {
    auto bigest = max_element(vw.begin(), vw.end());
    auto viter = ((bigest) - (vw).begin() + (value).begin());
    auto witer = ((bigest) - (vw).begin() + (weight).begin());
    auto s = (float) max_size / (float) *witer * (*viter);
    return s;
}

int zo_knapsack(int max_size, const vector<int> &value, const vector<int> &weight) {
    int i, w;
    int K[value.size() + 1][max_size + 1];
    for (i = 0; i <= value.size(); i++) {
        for (w = 0; w <= max_size; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[value.size()][max_size];
}
int main(){
    vector<int> value={0,65,20,30,60,40};
    vector<int> weight={0,3,1,2,5,4};
    vector<float> vw={2, 1.5, 2.1, 1, 1.2};
    cout<<zo_knapsack(100,value,weight)<<endl;
    cout<<fractional_knapsack(100,value,weight,vw)<<endl;
    return 0;
}
