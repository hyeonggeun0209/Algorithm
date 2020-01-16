#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; // n: vertex(정점)의 개수, m: edge(간선)의 개수
int s, e; // s: start(시작지점), e: end(끝지점)
vector<vector<int>> adjArray; //vector-vector를 선언
vector<int> inDeg; // 진입간선 수
queue<int> q; // 진입간선이 0인 정점을 저장하는 큐
vector<int> A; // 결과값 저장 (0 ~ A.size()-1)

void AddEdge(int start, int end) {
	adjArray[start].push_back(end);
}

void topologicalSort1() {
	for (int i = 1; i <= n; i++)
		if (inDeg[i] == 0) // 진입간선이 0이면 q에 enqueue
			q.push(i);
	for (int i = 1; i <= n; i++) {
		int u = q.front();
		q.pop();
		A.push_back(u);
		for (int j = 0; j < adjArray[u].size(); j++) {
			int v = adjArray[u][j];
			inDeg[v]--;
			if (inDeg[v] == 0)
				q.push(v);
		}
	}
}

int main() {
	cin >> n >> m;
	adjArray.resize(n + 1);
	inDeg.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		AddEdge(s, e);
		inDeg[e]++; // 진입간선의 수를 증가
	}
	topologicalSort1();
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
}