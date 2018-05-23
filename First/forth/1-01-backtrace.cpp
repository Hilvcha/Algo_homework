#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> value = {20, 30, 65, 40, 60};
vector<double> weight = {10, 20, 30, 40, 50};
int max_size = 100;
int n = weight.size();
int capacity = 10;
int maxValue = 0;
int tempValue;
int tempWeight;
vector<int> way = {n,0};
vector<int> bestWay ={n,0} ;
// 用于计算剩余物品的最高价值上界
double Bound(int k){
    double maxLeft = tempValue;
    int leftWeight = capacity - tempWeight;
    // 尽力依照单位重量价值次序装剩余的物品
    while(k <= n-1 && leftWeight > weight[k] ){
        leftWeight -= weight[k];
        maxLeft += value[k];
        k++;
    }
    // 不能装时，用下一个物品的单位重量价值折算到剩余空间。
    if( k <= n-1){
        maxLeft += value[k]/weight[k]*leftWeight;
    }
    return maxLeft;
}
void BackTrack(int t){
    // 已经搜索到根节点
    if(t>n-1){
        if(tempValue> maxValue){
            maxValue = tempValue;
            for(int i=0;i<n;i++)
                bestWay[i] = way[i];
        }
        return;
    }
    // 搜索左边节点
    if(tempWeight + weight[t] <= capacity){
        tempWeight += weight[t];
        tempValue += value[t];
        way[t] = 1;
        BackTrack(t+1);
        tempWeight -= weight[t];
        tempValue -= value[t];
        way[t] = 0;
    }
    // 不装入这个物品，直接搜索右边的节点
    if( Bound(t+1) >= maxValue){
        BackTrack(t+1);
    }
}



int main(){

    BackTrack(0);
    cout<<maxValue<<endl;
    for(int i=0;i<n;i++){
        cout<<bestWay[i]<<' ';
    }

    return 0;
}
