#include <iostream>
#include <vector>
#include <queue>
#define INF INT_MAX
using namespace std;

typedef struct {
	int vertex;
	int weight;
} Node;
bool operator>(Node a, Node b) {
	return (a.weight > b.weight);
}

priority_queue<Node, vector<Node>, greater<Node>> minHeap;
int n, m;
int s, e, w;
vector<vector<Node>> adjArray;
vector<bool> selected; // 각 노드가 트리에 포함되었는지 확인
vector<int> d; // 트리 내의 노드로부터 각 노드까지의 최소 비용
vector<int> pre; // 각 노드에 연결된 노드

void Prim(int s) {
	int numSelectedNode = 0;
	Node node;
	d[s] = 0;
	node.vertex = s;
	node.weight = 0;
	minHeap.push(node);
	while (numSelectedNode < n) {
		int u = minHeap.top().vertex;
		minHeap.pop();
		if (selected[u] == true)
			continue;
		selected[u] = true;
		numSelectedNode++;
		cout << u << "," << pre[u] << "(" << d[u] << ")" << endl;		for (int j = 0; j < adjArray[u].size(); j++) {
			int v = adjArray[u][j].vertex;
			int w = adjArray[u][j].weight;
			if (selected[v] == false && w < d[v]) {
				d[v] = w;
				pre[v] = u;
				node.vertex = v;
				node.weight = w;
				minHeap.push(node);
			}
		}
	}
}int main() {
	cin >> n >> m;
	adjArray.resize(n + 1);
	selected.resize(n + 1, false);
	d.resize(n + 1, INF);
	pre.resize(n + 1, -1);
	Node node;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> w;
		node.vertex = e;
		node.weight = w;
		adjArray[s].push_back(node);
		node.vertex = s;
		node.weight = w;
		adjArray[e].push_back(node);
	}
	Prim(1);
	int cost = 0;
	for(int i = 1; i <= n; i++)
		cost += d[i];
	cout << "Total Cost: " << cost;
}