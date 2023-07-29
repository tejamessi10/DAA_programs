#include <stdio.h>
#include <stdlib.h>
int n,i,j,a[20][20],q[20],visited[20],f=0,r=-1;
void bfs(int v)
{
    for(i=1;i<=n;i++)
    {
        if(a[v][i]&&!visited[i])
        {
            q[++r]=i;

        }
    }
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[++f]);
    }
}
int main ()
{
    int v;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    for(i = 1;i<=n;i++)
    {
        visited[i]=0;
        q[i]=0;
    }
    printf("\nEnter the graph in matrix form: ");
    for(i = 1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter the starting vertex:");
    scanf("%d",&v);
    bfs(v);
    printf("\nThe node which are reachable are:\n");
    for(i =1;i<=n;i++)
    {
        if(visited[i])
        printf("\t%d",i);
    }
    return 0;
}

//Enter the number of vertices:4

//Enter the graph data in the matrix form:
//0 1 1 1
//0 0 0 1
//0 0 0 0
//0 0 1 0

//Enter the starting vertex:1

//The node which are reachable are:
//2       3       4
