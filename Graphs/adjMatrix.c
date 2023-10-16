#include <stdio.h>
#define MAX 50
typedef struct graph
{
    int n;
    int a[MAX][MAX];
} graph;

void createGraph(graph *g)
{
    int i,j;
    for(i=0;i<g->n;i++)
        for(j=0;j<g->n;j++)
            g->a[i][j]=0;
    while(1)
    {
        printf("Enter source and destination \n");
        scanf("%d %d", &i, &j);
        if(i<0 || j<0 || i>=g->n || j>=g->n)
            break;
        g->a[i][j]=1; // for directed graph
        g->a[j][i]=1; // for undirected graph
    }
}

void display(graph *g)
{
    int i,j;
    for(i=0;i<g->n;i++)
    {
        for(j=0;j<g->n;j++)
            printf("%d ", g->a[i][j]);
        printf("\n");
    }
}
int main()
{
    graph g;
    printf("Enter the number of vertices:\n");
    scanf("%d", &g.n);
    createGraph(&g);
    display(&g);
}