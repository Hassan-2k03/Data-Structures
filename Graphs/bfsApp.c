/* Find all the nodes which are present at a particular level(“levelToCount”) ) in a directed graph represented as an adjacency
matrix “graph” ( int graph[][] ) which is rooted at “startVertex”. “vertices” represents the total number of nodes present in
the graph. Store all the answer nodes in the array given by “ansNodes” and return the total number of answer nodes. Note: Assume
index of first level is 0

The vertices are labelled from 0 to vertices-1.

If graph[i][j]=1 then there exists a directed edge from vertex i to vertex j.

Input Format

4 //Number of nodes in the graph
3 //Number of edges in the graph
0 1 //Represents edge
0 2 //Represents edge from 0 to 2
2 3 //Represents edge from 2 to
3 0 //startVertex(root of graph)
1 //leveltoCount i.e the level at which all the nodes present has to be found

Constraints

n>1 - No.of nodes in a graph m>0 - No.of edges in a graph

Output Format

1 2

Sample Input 0

4
3
0 1
0 2
2 3
0
1
Sample Output 0

1 2 */

// solution

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int countNodesAtLevel(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex, int levelToCount, int ansNodes[])
{
    bool visited[MAX_VERTICES] = {false}; 
    int level[MAX_VERTICES] = {0};        
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = true;
    level[startVertex] = 0;

    int nodeCount = 0;

    while (front < rear)
    {
        int currentVertex = queue[front++];

        if (level[currentVertex] == levelToCount)
            ansNodes[nodeCount++] = currentVertex;
        for (int i = 0; i < vertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = true;
                level[i] = level[currentVertex] + 1;
            }
        }
    }

    return nodeCount;
}

int main()
{
    int vertices, startVertex, levelToCount;

    // Input the number of vertices and starting vertex
    scanf("%d", &vertices);
    int edges;

    scanf("%d", &edges);

    int graph[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        scanf("%d %d", &source, &destination);
        graph[source][destination] = 1;
    }

    // Input the starting vertex for BFS
    scanf("%d", &startVertex);

    // Input the level to count
    scanf("%d", &levelToCount);

    int ansNodes[MAX_VERTICES];
    int nodeCount = countNodesAtLevel(graph, vertices, startVertex, levelToCount, ansNodes);

    for (int i = 0; i < nodeCount; i++)
    {
        printf("%d ", ansNodes[i]);
    }

    return 0;
}