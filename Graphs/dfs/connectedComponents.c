/** Given a undirected graph represented in adjency matrix write a function using dfs to find the number of connected components. */

#include <stdio.h>
#include <stdlib.h>

#define max 100
#define visited 1
#define initial 0
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
            a[origin][des] = a[des][origin] = 1;
    }
}

void dfs(int v)
{
    int i;
    state[v] = visited;
    for (i = 0; i < n; i++)
        if (a[v][i] == 1 && state[i] == initial)
            dfs(i);
}

int component()
{
    int i, label = 0;
    for (i = 0; i < n; i++)
        if (state[i] == initial)
        {
            label++;
            dfs(i);
        }
    return label;
}

int main()
{
    create_graph();
    int label = component();
    printf("Number of connected components: %d", label);
    return 0;
}