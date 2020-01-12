#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF INT_MAX
typedef struct {
	int vertax;
	int weight;
} Node;

bool operator>(Node a, Node b) {
	return (a.weight > b.weight);
}

priority_queue<Node, vector<Node>, greater<Node>> minHeap;

int n, m, start_node;
int s, e, w;
vector<vector<Node>> adjArray;
vector<bool> selected;
vector<int> d;
vector<int> pre;

void Dijkstra() {




}

int extractMin(Q, d[]) {

}

int main() {
	cin >> n >> m >> start_node;
	adjArray.resize(n + 1);
	selected.resize(n + 1, false);
	d.resize(n + 1, INF);
	pre.resize(n + 1, -1);

	Node node;
	for (int i = 0; i < m; i++) {
		cin >> s >> e << w;
		node.vertax = e;
		node.weight = w;
		adjArray[s].push_back(node);

		node.vertax = s;
		node.vertax = w;
		adjArray[e].push_back(node);
	}
}