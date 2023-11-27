// write a program to check wheather the given graph is cyclic or not

#include <stdio.h>
#include <stdlib.h>

#define max 100
#define visited 2
#define initial 1
#define finished 3

int a[max][max];
int state[max];
int n; 

void create_graph()
{
    int i, max_edges, origin, des;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    max_edges = n * (n - 1);
    for (i = 0; i < max_edges; i++)
    {
        printf("Enter the source and destination ");
        scanf("%d %d", &origin, &des);
        if (origin == -1 && des == -1)
            break;
        if (origin >= n || des >= n || origin < 0 || des < 0)
        {
            printf("Invalid edge\n");
            i--;
        }
        else
            a[origin][des] = 1;
    }
}

void dfs(int v)
{
    int i;
    state[v]=visited;
    for(i=0; i<n; i++)
        if(a[v][i]==1)
            if(state[i]==initial)
                dfs(i);
            else if (state[i]==visited)
            {
                printf("Graph is cyclic\n");
                exit(1);
            }
    state[v]=finished;
}
void dfsTraversal()
{
    int v;
    for (v = 0; v < n ; v++)
        state[v] = initial;
    dfs(0);
    for(v=0;v<n;v++)
        if(state[v]==initial)
            dfs(v);
    printf("Graph is Acyclic");
}


int main()
{
    create_graph();
    dfsTraversal();
    return 0;
}