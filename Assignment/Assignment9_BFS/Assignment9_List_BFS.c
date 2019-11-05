#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define Q_SIZE 20

typedef struct node {
	int vertex;
	struct node *next;
} Node;

typedef struct {
	int vertexNum;
	int **adjList;
} Graph;

typedef struct {
	int queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType *createQueue() {
	QueueType *Q;
	Q = (QueueType *)malloc
	(sizeof(QueueType));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

int isEmpty(QueueType *Q) {
	if (Q->front == Q->rear) {
		return 1;
	}
	else
		return 0;
}

int isFull(QueueType *Q) {
	if ((Q->rear + 1) % Q_SIZE == Q->front % Q_SIZE) {
		return 1;
	}
	else return 0;
}
void enQueue(QueueType *Q, int item) {
	if (isFull(Q)) return;
	else {
		Q->rear = (Q->rear + 1) % Q_SIZE;
		Q->queue[Q->rear] = item;
	}
}
int deQueue(QueueType *Q) {
	if (isEmpty(Q))
		return -1;
	else {
		Q->front = (Q->front + 1) % Q_SIZE;
		return Q->queue[Q->front];
	}
}

int *visited;

Graph *NewGraph(int vNum) {
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->vertexNum = vNum;
	graph->adjList = (int **)malloc(sizeof(int *)*(vNum + 1));
	for (int i = 0; i <= vNum; i++)
		graph->adjList[i] = NULL;

	visited = (int *)malloc(sizeof(int)*(vNum + 1));

	return graph;
}

void AddEdge(Graph *g, int start, int end) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->vertex = end;
	newNode->next = g->adjList[start];
	g->adjList[start] = newNode;

	newNode = (Node *)malloc(sizeof(Node));
	newNode->vertex = start;
	newNode->next = g->adjList[end];
	g->adjList[end] = newNode;
}
void printGraph(Graph *graph) {
	Node *p;
	for (int i = 1; i <= graph->vertexNum; i++) {
		p = graph->adjList[i];
		printf("%d: ", i);
		while (p != NULL) {
			printf("%d ", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
}

void BFS_List(Graph *g, int s) {
	QueueType *BFS_Q = createQueue();
	for (int i = 1; i <= g->vertexNum; i++) {
		if (i == s) continue;
		visited[i] = 0;
	}
	visited[s] = 1;
	enQueue(BFS_Q, s);
	int u;
	while (!isEmpty(BFS_Q)) {
		u = deQueue(BFS_Q);
		printf("%d ", u);
		Node *p;
		p = g->adjList[u];
		while (p != NULL) {
			if (visited[p->vertex] == 0) {
				visited[p->vertex] = 1;
				enQueue(BFS_Q, p->vertex);
				p = p->next;
			}
			else
				p = p->next;
		}

	}

	free(BFS_Q);
}

int main() {
	Graph *g = NewGraph(8);

	AddEdge(g, 1, 2);
	AddEdge(g, 1, 3);
	AddEdge(g, 2, 4);
	AddEdge(g, 2, 5);
	AddEdge(g, 3, 5);
	AddEdge(g, 3, 7);
	AddEdge(g, 3, 8);
	AddEdge(g, 4, 5);
	AddEdge(g, 5, 6);
	AddEdge(g, 7, 8);

	printGraph(g);
	printf("\nBFS: ");
	BFS_List(g, 1);
}
