#include<stdio.h>
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

int inDegree(graph *g,int ver)
{
    int i,deg=0;
    for(i=0;i<g->n;i++)
        if(g->a[i][ver]==1)
            deg++;
    return deg;
}

int outDegree(graph *g,int ver)
{
    int i,deg=0;
    for(i=0;i<g->n;i++)
        if(g->a[ver][i]==1)
            deg++;
    return deg;
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
    printf("Enter the vertex to find in-degree:\n");
    int ver;
    scanf("%d", &ver);
    printf("In-degree of %d is %d\n", ver, inDegree(&g,ver));
    printf("Out-degree of %d is %d\n", ver, outDegree(&g,ver));
}

