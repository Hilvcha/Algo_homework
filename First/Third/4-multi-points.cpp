#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void print_D(vector<vector<int> > &matrix) {
    for (auto& i:matrix) {
        for (auto j:i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

int Floyd(const vector<std::vector<int> > &matrix) {
    vector<vector<int> > dist{matrix.size(),vector<int> {(int)(matrix.size()), 0}};
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            dist[i][j] = i == j ? 0 : matrix[i][j];
        }
    }
    cout << '\n';
    print_D(dist);
    for (int k = 0; k < dist.size(); ++k) {
        for (int i = 0; i < dist.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                dist[i][j] =min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    print_D(dist);
    return dist[0][matrix.size()-1];
}
int main(){
    vector<vector<int> > res{5, vector<int>{5, INT_MAX}};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> res[i][j];
            res[i][j] = res[i][j] == 0 ? INT_MAX : res[i][j];
        }
    }
    Floyd(res);
    return 0;
}
