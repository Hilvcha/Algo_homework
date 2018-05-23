#include<iostream>
#include<string>
#include<vector>

using namespace std;
//邻接矩阵表示带权图
const int INFINIFY = INT_MAX;
const int MAX_VERTEX_NUM = 20;
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef int VRType;
typedef struct AreCell {
	//顶点
	VRType adj;
	string info;
}AreCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	//图ADT
	vector<int> vexs;
	AdjMatrix arcs;
	int vexn, arcn;
	GraphKind kind=UDN;
}MGraph;
int CreateGraph(MGraph & G);
int CreateUDN(MGraph &G);
void ShortestPath_DIJ(MGraph G, int V0, vector<int> &path, int target);

int CreateGraph(MGraph & G) {
	//创建图
	int tempkind;
	cin >> tempkind;
	G.kind = GraphKind(tempkind);
	switch (G.kind){
	case UDN:return CreateUDN(G);
	default:
		break;
	}
	return 0;
}
int CreateUDN(MGraph &G) {
	//采用邻接矩阵表示无向网G
	//cin >> G.vexn >> G.arcn;
	G.vexn = 16;
	G.arcn = 30;
	//录入顶点数和弧数
	for (int i = 0; i != G.vexn; i++) {
	//顶点向量内顶点名称与下标相对应
		G.vexs.push_back(i);
	}
	//初始化权为无穷大
	for (int i = 0; i != G.vexn; i++) {
		for (int j = 0; j != G.vexn; j++) {
			AreCell tempnode = {
				INFINIFY,
				"",
			};
			G.arcs[i][j] = tempnode;
			if (i == j) {
				G.arcs[i][j].adj = 0;
			}
		}
	}
	//for (int k = 0; k != G.arcn; k++) {
	//	int i, j,w;
	//	cin >> i >> j >> w;
	//	G.arcs[i][j].adj = w;

	//}
	G.arcs[0][1].adj = 5;	G.arcs[0][2].adj = 3;
    G.arcs[1][0].adj = 5;	G.arcs[1][3].adj = 1;	G.arcs[1][4].adj = 3;	G.arcs[1][5].adj = 6;
    G.arcs[2][0].adj = 3;	G.arcs[2][4].adj = 8;	G.arcs[2][5].adj = 7;	G.arcs[2][6].adj = 6;
    G.arcs[3][1].adj = 1;	G.arcs[3][7].adj = 6;	G.arcs[3][8].adj = 8;
    G.arcs[4][1].adj = 3;	G.arcs[4][7].adj = 3;	G.arcs[4][8].adj = 5;
    G.arcs[5][1].adj = 5;	G.arcs[5][2].adj = 7;	G.arcs[5][8].adj = 3;	G.arcs[5][9].adj = 3;
    G.arcs[6][2].adj = 6;	G.arcs[6][8].adj = 8;	G.arcs[6][9].adj = 4;
    G.arcs[7][3].adj = 6;	G.arcs[7][4].adj = 3;	G.arcs[7][10].adj = 2;	G.arcs[7][11].adj = 2;
    G.arcs[8][3].adj = 8;	G.arcs[8][4].adj = 5;	G.arcs[8][5].adj = 3;	G.arcs[8][6].adj = 3;	G.arcs[8][11].adj = 1;	G.arcs[8][12].adj = 2;
    G.arcs[9][5].adj = 3;	G.arcs[9][6].adj = 4;	G.arcs[9][11].adj = 3;	G.arcs[9][12].adj = 3;
    G.arcs[10][7].adj = 2;	G.arcs[10][13].adj =3;	G.arcs[10][14].adj = 5;
    G.arcs[11][7].adj = 2;	G.arcs[11][8].adj = 1;	G.arcs[11][9].adj = 3;	G.arcs[11][13].adj = 5;	G.arcs[11][14].adj = 2;
    G.arcs[12][8].adj = 2;	G.arcs[12][9].adj = 3;	G.arcs[12][13].adj =6;	G.arcs[12][14].adj = 6;
    G.arcs[13][10].adj =3;	G.arcs[13][11].adj =5;	G.arcs[13][12].adj =6;	G.arcs[13][15].adj = 4;
    G.arcs[14][10].adj =5;	G.arcs[14][11].adj =2;	G.arcs[14][12].adj =6;	G.arcs[14][15].adj = 3;
    G.arcs[15][13].adj =4;	G.arcs[15][14].adj =3;
	return 0;
}

void ShortestPath_DIJ(MGraph G, int V0, vector<int> &path,int target) {
	typedef struct table
	{
		int d;
		int v;
	} D_table;
	D_table D[MAX_VERTEX_NUM];
	bool S[MAX_VERTEX_NUM];
	for (int i = 0; i < G.vexn; i++) {
		D[i].d = INFINIFY;
	}
	D[0].d = 0;
	for (int i = 0; i < G.vexn; i++) {
		S[i] = false;
	}
	int Q = G.vexn;
	while (Q != 0) {
		int v = 0;
		int min_d = INFINIFY;
		for (int i = 0; i < G.vexn; i++) {
			if (S[i]) {
				continue;
			}
			if (min_d > D[i].d) {
				min_d = D[i].d;
				v = i;
			}
		}
		S[v] = true;
		Q--;
		for (int i = 0; i < G.vexn; i++) {
			if (G.arcs[v][i].adj < INFINIFY) {
				//relax v->i
				if (G.arcs[v][i].adj + D[v].d < D[i].d) {
					D[i].d = G.arcs[v][i].adj + D[v].d;
					D[i].v = v;
				}
			}
		}

	}
	D[V0].v = -1;
	int i = target;
	while (D[i].v != -1) {
		path.push_back(i);
		i = D[i].v;
	}

	cout<<"The shortest path is:"<<endl << V0 << ends;
	while (!path.empty()) {
		cout << "->" << path.back() <<ends;
		path.pop_back();
	}
	cout <<endl<< "The shortest distance is : " << D[target].d << endl;
}
int main() {
	MGraph G;
	CreateUDN(G);
	cout << "please input your source:" << endl;
	int v0 = 0,target=0;
	cin >> v0;
	cout << "please input your destination:" << endl;
	cin >> target;
	vector<int> path;
	ShortestPath_DIJ(G, v0, path, target);

	//system("pause");
	return 0;
}



