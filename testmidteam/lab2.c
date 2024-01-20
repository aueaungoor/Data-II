#include<stdio.h>


int doit(int i , int j)
{
    if(j == 0){
        return 1;
    }
    else if(i == j)
    {
         return 1;
    }
    else{
        return doit(i-1 , j) + doit(i-1 , j-1);
    }
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int a = doit(i,j);
            printf("%d",a);
        }
        printf("\n");
        
    }
    
}