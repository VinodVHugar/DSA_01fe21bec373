#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
};

struct Stack {
    int items[MAX_NODES];
    int top;
};

void initializeGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void DFS(struct Graph* graph, int startNode) {
    struct Stack stack;
    int visited[MAX_NODES] = {0};

    initializeStack(&stack);
    push(&stack, startNode);

    while (!isStackEmpty(&stack)) {
        int currentNode = pop(&stack);

        if (!visited[currentNode]) {
            printf("%d ", currentNode);
            visited[currentNode] = 1;
        }

        for (int i = 0; i < graph->numNodes; i++) {
            if (graph->adjMatrix[currentNode][i] && !visited[i]) {
                push(&stack, i);
            }
        }
    }
}

int main() {
    struct Graph graph;
    int numNodes, numEdges, src, dest;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    initializeGraph(&graph, numNodes);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("DFS traversal: ");
    DFS(&graph, startNode);

    return 0;
}
