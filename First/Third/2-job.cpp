#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int schedule(vector<int> &job) {
    sort(job.rbegin(), job.rend());
    cout << job[0] << '\n';
    int res = 0;
    for (int i = 0; i < job.size(); ++i) {
        res += (i+1) * job[i];
    }
    return res / job.size();
}
int main () {
    vector<int> job={1,8,3,10};
    cout << schedule(job) << endl;
    return 0;
}
