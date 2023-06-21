// Program to implement graph and perform deletion.
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef struct
{
    int adj_matrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;

void printGraph(Graph *graph)
{
    int i, j;

    printf("Adjacency Matrix:\n");

    for (i = 0; i < graph->numNodes; i++)
    {
        for (j = 0; j < graph->numNodes; j++)
        {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayDFS(Graph *graph, int startNode)
{
    int stack[MAX_NODES];
    int top = -1;
    int visited[MAX_NODES] = {0};
    int i, currentNode;
    printf("DFS Traversal: ");
    visited[startNode] = 1;
    printf("%d ", startNode);
    stack[++top] = startNode;
    while (top != -1)
    {
        currentNode = stack[top--];

        for (i = 0; i < graph->numNodes; i++)
        {
            if (graph->adj_matrix[currentNode][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                printf("%d ", i);
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

void displayBFS(Graph *graph, int startNode)
{
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int visited[MAX_NODES] = {0};
    int i, currentNode;
    printf("BFS Traversal: ");
    visited[startNode] = 1;
    printf("%d ", startNode);
    queue[rear++] = startNode;

    while (front != rear)
    {
        currentNode = queue[front++];

        for (i = 0; i < graph->numNodes; i++)
        {
            if (graph->adj_matrix[currentNode][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void createGraph(Graph *graph, int numNodes)
{
    int i, j;
    graph->numNodes = numNodes;

    // Initialize all matrix elements to 0
    for (i = 0; i < numNodes; i++)
    {
        for (j = 0; j < numNodes; j++)
        {
            graph->adj_matrix[i][j] = 0;
        }
    }
}

void insertNode(Graph *graph)
{
    if (graph->numNodes == MAX_NODES)
    {
        printf("Maximum number of nodes reached.\n");
        return;
    }

    // Node increment
    graph->numNodes++;
}

void insertEdge(Graph *graph, int node1, int node2)
{
    if (node1 >= graph->numNodes || node2 >= graph->numNodes)
    {
        printf("Invalid node.\n");
        return;
    }

    // Flip 0 to 1
    graph->adj_matrix[node1][node2] = 1;
    graph->adj_matrix[node2][node1] = 1;
}

void deleteEdge(Graph *graph, int node1, int node2)
{
    if (node1 >= graph->numNodes || node2 >= graph->numNodes)
    {
        printf("Invalid node.\n");
        return;
    }

    // Disconnect the nodes in the adjacency matrix
    graph->adj_matrix[node1][node2] = 0;
    graph->adj_matrix[node2][node1] = 0;
}

void deleteNode(Graph *graph, int node)
{
    if (node >= graph->numNodes)
    {
        printf("Invalid node.\n");
        return;
    }

    int i, j;

    // Shift the nodes and edges to remove the node
    for (i = node; i < graph->numNodes - 1; i++)
    {
        for (j = 0; j < graph->numNodes; j++)
        {
            graph->adj_matrix[j][i] = graph->adj_matrix[j][i + 1];
        }
    }

    for (i = node; i < graph->numNodes - 1; i++)
    {
        for (j = 0; j < graph->numNodes; j++)
        {
            graph->adj_matrix[i][j] = graph->adj_matrix[i + 1][j];
        }
    }
    graph->numNodes--;
}

int main()
{
    Graph graph;
    int numNodes = 5;

    createGraph(&graph, numNodes);

    insertNode(&graph);
    insertNode(&graph);

    insertEdge(&graph, 0, 1);
    insertEdge(&graph, 0, 2);
    insertEdge(&graph, 1, 2);
    insertEdge(&graph, 2, 3);
    insertEdge(&graph, 3, 4);
    insertEdge(&graph, 4, 5);
    insertEdge(&graph, 5, 6);

    printf("Before Deletion:\n");
    printGraph(&graph);
    printf("\n");

    deleteEdge(&graph, 0, 2);
    deleteNode(&graph, 4);

    printf("After Deletion:\n");
    printGraph(&graph);
    printf("\n");

    displayBFS(&graph, 0);
    displayDFS(&graph, 0);
    return 0;
}