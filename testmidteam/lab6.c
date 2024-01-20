#include <stdio.h>
#define MAX 10

 int mat[MAX][MAX];
    int n;

int status[MAX] = {0};
int queue[10];
void bfs(int source)
{
    int  front = -1 , rear = -1 , count = 0;
    status[source] = 1;
    queue[++rear] = source;
    count++;
    front = 0;
    while(count != 0)
    {
        int v = queue[front++];
        count--;
        printf("%d", v+ 1);
        for (int i = 0; i < MAX ; i++)
        {
             if(mat[v][i] == 1 && status[i] == 0)
             {
                status[i] = 1;
                queue[++rear] = i;
                count++;
             }
        }
    }

}

void main()
{

    printf("Enter the number of Vertices in the Graph : ");
    scanf("%d",&n);
    printf("Enter the adjacency Matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&mat[i][j]);
        }  
    }
    int start;
    printf("Enter the Source :");
    scanf("%d",&start);

    bfs(start - 1);
    
}