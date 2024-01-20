#include<stdio.h>
#define MAX 10

int n;
int adj[MAX][MAX];
int visted[MAX];


void setgraph()
{
    int i , j ;
    printf("Enter number of vertices in Graph:");
    scanf("%d",&n);

    printf("Enter the adjacency Matrix\n\n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    for(i = 0 ; i < n ; i++)
    {
         visted[i] = 0;
    }
    
}


void bfs(int source)
{
    int queue[MAX];
    int i , v ,count = 0, head = -1;
    visted[source] = 1;
    queue[++head] = source;
    count++;
    while(count != 0)
    {
        v = queue[head--];
        count--;
        printf("%d ",v+1);
        for(i = 0 ; i < n ;i++)
        {
            if(adj[v][i] == 1 && visted[i] == 0)
            {
                visted[i] = 1;
                queue[++head] = i;
                count++;
            }
        }
    }

}
int main()
{
    int source;
    setgraph();

    printf("Enter the Source:");
    scanf("%d",&source);

    printf("The nodes visted in BFS order is: ");
    bfs(source - 1);
}