/* Find the total number of paths from startNode(label of start node) to endNode(label of end node) in a directed graph represented
as an adjacency matrix “graph” ( int graph[][] ). Given the total number of vertices represented by “vertices”( int vertices)
, complete the function “countPaths” which returns the total number of path present in the graph between the startNode and
endNode.

Note:

The vertices are labelled from 0 to vertices-1.

If graph[i][j]=1 then there exists a directed edge from vertex i to vertex j.

Input Format

3 //Number of nodes in the graph
3 //Number of edges in the graph
0 1 //Represents edge from 0 to 1
1 2 //Represents edge from 1 to 2
0 2 //Represents edge from 0 to 2
0 //Represents start node
2 //Represents end node

Output Format

2 //total number of path present in the graph between the startNode and endNode

Sample Input 0

3
3
0 1
1 2
0 2
0
2
Sample Output 0

2 */

// solution

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100



// Function to count the total number of paths from the start node to the end node in a directed graph
int countPaths(int graph[MAX_NODES][MAX_NODES], int vertices, int startNode, int endNode)
{
    // Write your code here
    int count = 0;
    int visited[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    visited[startNode] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (graph[startNode][i] == 1 && visited[i] == 0)
        {
            if (i == endNode)
                count++;
            else
                count += countPaths(graph, vertices, i, endNode);
        }
    }
    return count;
}

int main()
{

    // Driver's Code
    int vertices;
    int graph[MAX_NODES][MAX_NODES];

    int startNode;
    int endNode;

    scanf("%d", &vertices);
    int edges;

    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        scanf("%d %d", &source, &destination);
        graph[source][destination] = 1;
    }

    scanf("%d", &startNode);
    scanf("%d", &endNode);

    int totalPaths = countPaths(graph, vertices, startNode, endNode);

    printf("%d", totalPaths);

    return 0;
}