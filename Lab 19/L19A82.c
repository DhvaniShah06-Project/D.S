#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *link;
};
struct graph
{
    int vertice;
    struct node **adjList;
    int *visited;
};
void DFS(struct graph *graph, int);
void BFS(struct graph *graph, int);
void ADDEdge(struct graph *graph, int, int);
struct graph *createGraph(int);
struct node *createNode(int);

int main()
{
    int vertex = 5;
    struct graph *graph = createGraph(vertex);
    ADDEdge(graph, 0, 1);
    ADDEdge(graph , 0, 2);
    ADDEdge( graph, 1, 3);
    ADDEdge( graph, 1, 4);
    ADDEdge( graph, 2, 4);
    DFS( graph, 0);
    BFS( graph,0);
    return 0;
}

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->link = NULL;
    return newNode;
}

struct graph *createGraph(int vertice)
{
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
     graph->vertice = vertice;
    graph->adjList = malloc(vertice * sizeof(struct node *));
    graph->visited = (int *)malloc(vertice * sizeof(int));
    for (int i = 0; i < vertice; i++)
    {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void ADDEdge(struct graph *graph, int src, int dest)
{

    /*0 thi 1 ni edge mate*/
    struct node *newNode = createNode(dest);
    newNode->link = graph->adjList[src];
    graph->adjList[src] = newNode;

    /*1 thi 0 ni edge mate as undirected graph*/
    newNode = createNode(src);
    newNode->link = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void DFS(struct graph *graph, int vertex)
{
    struct node *adjList = graph->adjList[vertex];
    struct node *temp = adjList;
    graph->visited[vertex] = 1;
    printf("DFS Traversal : %d\n",vertex);
    while (temp != NULL)
    {
        int connectedvertex = temp->vertex;
        if (graph->visited[connectedvertex] == 0)
            DFS(graph, connectedvertex);
        temp = temp->link;
    }
}

void BFS(struct graph *graph, int startvertex)
{
    int MAX =10;
    int queue[MAX], f = 0, r = 0;
    for (int i = 0; i < graph->vertice; i++)
    {
        graph->visited[i] = 0;
    }
        graph->visited[startvertex] = 1;
        queue[r++] = startvertex;
        while (f < r)
        {
            int currentvertex = queue[f++];
            printf("BFS Traversal : %d\n",currentvertex);
            struct node *temp = graph->adjList[currentvertex];
            while (temp != NULL)
            {
                int adjVertex = temp->vertex;
                if (graph->visited[adjVertex] == 0)
                {
                    graph->visited[adjVertex] = 1;
                    queue[r++] = adjVertex;
                }
                temp = temp->link;
            }
        
    }
}