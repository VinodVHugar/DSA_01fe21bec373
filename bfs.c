#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Queue data structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Initialize an empty queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
bool isFull(Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Add an element to the rear of the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue.\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Remove an element from the front of the queue
int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

// Perform Breadth First Search
void bfs(int graph[][MAX_SIZE], int vertices, int startVertex) {
    bool visited[MAX_SIZE];
    Queue queue;

    for (int i = 0; i < vertices; i++) {

        visited[i] = false;
    }

    initQueue(&queue);
    visited[startVertex] = true;
    printf("BFS traversal: ");

    enqueue(&queue, startVertex);

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&queue, i);
                visited[i] = true;
            }
        }
    }
}

// Test the BFS algorithm
int main()
{
    int vertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
     {
        for (int j = 0; j < vertices; j++)
            {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    bfs(graph, vertices, startVertex);

    return 0;
}
